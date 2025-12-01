#include <bits/stdc++.h>

using namespace std;

void part1(const vector<char> directions, const vector<int> distances)
{
    int result = 0;

    int dial = 50;
    for (int i = 0; i < directions.size(); i++)
    {
        if (directions.at(i) == 'L')
        {
            dial = (dial - distances.at(i)) % 100;
        }
        else 
        {
            dial = (dial + distances.at(i)) % 100;
        }

        // Check for 0
        if (dial == 0) result++;
    }

    cout << "part 1: " << result << endl;
}

void part2(const vector<char> directions, const vector<int> distances)
{
    int result = 0;

    int dial = 50;
    // Loop through each direction
    for (int i = 0; i < directions.size(); i++)
    {
        int x = distances.at(i);

        // L: Hits zero -> Count -> Jump to 99
        if (directions.at(i) == 'L')
        {
            for (int j = 0; j < distances.at(i); j++)
            {
                if (--dial < 0)
                {
                    dial = 99;
                }

                if (dial == 0)
                {
                    result++;
                }
            }
        }
        // R: Hits 100 -> Jump to 0 -> Count
        else
        {
            for (int j = 0; j < distances.at(i); j++)
            {
                if (++dial > 99) 
                {
                    dial = 0;
                }

                if (dial == 0)
                {
                    result++;
                }
            }
        }
    }

    cout << "part 2: " << result << endl;
}

int main()
{
    vector<char> directions;
    vector<int> distances;
    string line;

    while (getline(cin, line))
    {
        directions.push_back(line[0]);

        int dis = stoi(line.substr(1, -1));
        distances.push_back(dis);
    }

    part2(directions, distances);
}
