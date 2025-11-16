#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> directions = {
    {-1,-1},
    {-1,0},
    {-1,1},
    {0,-1},
    {0,1},
    {1,-1},
    {1,0},
    {1,1},
};

void part1(const vector<string> input)
{
    int counter = 0;
    const string needle = "XMAS";

    int rows = input.size();
    int cols = input[0].size();

    // Find all 'X' characters.
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            for (auto [dr, dc] : directions)
            {
                bool found = true;

                // Try to match all 4 letters
                for (int k = 0; k < 4; k++)
                {
                    int nr = row + dr * k, nc = col + dc * k;
                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || input[nr][nc] != needle[k])
                    {
                        found = false;
                        break;
                    }
                }

                if (found) counter++;
            }
        }
    }

    cout << endl << "part 1: " << counter << endl;
}

void part2(const vector<string> input)
{
    int counter = 0; 
    int rows = input.size();
    int cols = input[0].size();
    
    for (int i = 1; i < rows - 1; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            // Only looking for mid points 'A'
            if (input[i][j] != 'A') continue;

            string d1 = "";
            d1 += input[i-1][j-1];
            d1 += input[i][j];
            d1 += input[i+1][j+1];

            string d2 = "";
            d2 += input[i-1][j+1];
            d2 += input[i][j];
            d2 += input[i+1][j-1];

            if ((d1 == "MAS" || d1 == "SAM") &&
                (d2 == "MAS" || d2 == "SAM"))
            {
                counter++;
            }
        }
    }

    cout << endl << "part 2: " << counter << endl;
}

int main(void)
{
    vector<string> input;
    string line;

    while (getline(cin, line)) input.push_back(line);

    part1(input);
    part2(input);
}
