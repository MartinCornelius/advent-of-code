#include <bits/stdc++.h>

using namespace std;

void printGrid(const vector<string> grid)
{
	for (auto &row : grid) 
	{
		for (auto &col : row)
		{
			cout << " " << col;
		}
		cout << endl;
	}

	cout << "=======================" << endl << endl;
}

void part1(vector<string> grid)
{
	// Lab guard rules
	// 1. Something directly in front = turn right 90 degress.
	// 2. Otherwise, take a step forward. 
	int result = 0; 

	// Get location of the guard
	pair<int, int> guardPosition;
	for (int row = 0; row < grid.size(); row++)
	{
		for (int col = 0; col < grid.at(0).size(); col++)
		{
			if (grid[row][col] == '^')
				guardPosition = { row, col };
		}
	}
	cout << "row: " << guardPosition.first << " col: " << guardPosition.second << endl;

	pair<int, int> guardDirection = {-1,0};
	bool leftArea = false;

	while (!leftArea)
	{
		// Detect leaving map
		if (
			(guardPosition.first+guardDirection.first < 0) ||
			(guardPosition.first+guardDirection.first >= grid.size()) ||
			(guardPosition.second+guardDirection.second < 0) ||
			(guardPosition.second+guardDirection.second > grid[0].size())
			)
		{
			grid[guardPosition.first][guardPosition.second] = 'x';
			leftArea = true;
			break;
		}

		if (grid[guardPosition.first+guardDirection.first][guardPosition.second+guardDirection.second] == '.' 
			|| grid[guardPosition.first+guardDirection.first][guardPosition.second+guardDirection.second] == 'x')
		{
			// Update grid with new visited spot
			grid[guardPosition.first][guardPosition.second] = 'x';

			// Update guard position
			guardPosition.first = guardPosition.first+guardDirection.first;
			guardPosition.second = guardPosition.second+guardDirection.second;
		}
		else if (grid[guardPosition.first+guardDirection.first][guardPosition.second+guardDirection.second] == '#')
		{
			// Update grid with new visited spot
			grid[guardPosition.first][guardPosition.second] = 'x';

			// Changing direction
			guardDirection = {guardDirection.second, -guardDirection.first};

			// Update guard position
			guardPosition.first = guardPosition.first+guardDirection.first;
			guardPosition.second = guardPosition.second+guardDirection.second;
		}
		else
		{
			leftArea = true;
		}
	}

	// Count distinct grid locations
	for (auto &row : grid)
	{
		for (auto &col : row) 
		{
			if (col == 'x') result++;
		}
	}

	cout << "part 1: " << result << endl;
}

void part2()
{
}

int main(void)
{
	// Current position of the guard (^) - points upward
	// Obstructions marked with (#)
	vector<std::string> grid;
	string line;

	while (getline(cin, line))
		grid.push_back(line);

	part1(grid);
}