#include <bits/stdc++.h>

using namespace std;

void part1()
{
}

void part2()
{
}

int main()
{
    // Operators are evaluated left-to-right always!
    // add + and multiply * 
    vector<int> testValues;
    vector<vector<int>> numbers;
    string line;

    while(getline(cin, line))
    {
        // Find colon
        int cIdx = line.find(":");
        testValues.push_back(stoi(line.substr(0, cIdx)));

    }

    cout << "DONE!" << endl;
}
