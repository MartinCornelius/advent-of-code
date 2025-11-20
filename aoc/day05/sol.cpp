#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <iterator>
#include <utility>

using namespace std;

void part1(const vector<pair<int, int>> pageOrderingRules, const vector<vector<int>> updates)
{
    int result = 0;
    
    for (const vector<int> &update : updates)
    {
        bool isValid = true;
        
        // Check the rules iteratively for the line
        for (const pair<int, int> &rule : pageOrderingRules)
        {
            // Check that both values are in the line

            if (std::find(update.begin(), update.end(), rule.first) != update.end() && 
                std::find(update.begin(), update.end(), rule.second) != update.end())
            {
                // Check the order of the numbers
                ptrdiff_t x1 = distance(update.begin(), std::find(update.begin(), update.end(), rule.first));
                ptrdiff_t x2 = distance(update.begin(), std::find(update.begin(), update.end(), rule.second));
                if (x2 <= x1) isValid = false;
            }
        }
        
        // If valid add to result
        if (isValid)
            // TODO: Count the middle value
            result += update.at(update.size()/2);
    }

    cout << "part 1: " << result << endl;
}

bool isValid(const vector<pair<int, int>> pageOrderingRules, const vector<int> update)
{
    bool isValid = true;
        
        // Check the rules iteratively for the line
        for (const pair<int, int> &rule : pageOrderingRules)
        {
            // Check that both values are in the line

            if (std::find(update.begin(), update.end(), rule.first) != update.end() && 
                std::find(update.begin(), update.end(), rule.second) != update.end())
            {
                // Check the order of the numbers
                ptrdiff_t x1 = distance(update.begin(), std::find(update.begin(), update.end(), rule.first));
                ptrdiff_t x2 = distance(update.begin(), std::find(update.begin(), update.end(), rule.second));
                if (x2 <= x1) isValid = false;
            }
        }

    return isValid;
}

void part2(const vector<pair<int, int>> pageOrderingRules, vector<vector<int>> updates)
{
    int result = 0;

    for (auto &update : updates)
    {
        // Skip if already valid
        if (isValid(pageOrderingRules, update)) continue;

        vector<int> x;
        // iteratively switch around the numbers
        for (int i = 0; i < update.size(); i++)
        {
            x.push_back(update.at(i));
            if (isValid(pageOrderingRules, x))
            {
                continue;
            }
            else
            {
                for (int a = -1; a > x.size(); a--)
                {
                    // Switch around from the back until valid
                    swap(x.end()[a], x.end()[a-1]);                    
                    if (isValid(pageOrderingRules, x)) break;
                }
            }

        }
        result += x.at(x.size()/2);
    }

    cout << "part 2: " << result << endl;
}

int main(void)
{
    vector<pair<int, int>> pageOrderingRules;
    vector<vector<int>> updates;
    string line;

    bool isUpdate = false;

    while (getline(cin, line))
    {
        if (empty(line)) {isUpdate = true; continue;} 

        if (!isUpdate)
        {
            int splitIdx = line.find("|");
            pageOrderingRules.push_back(pair<int, int>{stoi(line.substr(0, splitIdx)), stoi(line.substr(splitIdx+1))});
        }
        else
        {
            size_t pos = line.find(",");
            size_t tmp = 0;
            vector<int> updateNums;
            while (pos != string::npos)
            {
                updateNums.push_back(stoi(line.substr(tmp, pos-tmp)));
                tmp = pos + 1;
                pos = line.find(",", pos+1);
            }
            // add the last number too
            updateNums.push_back(stoi(line.substr(tmp, line.size())));
            updates.push_back(updateNums);
        }
    }

    // part1(pageOrderingRules, updates);
    part2(pageOrderingRules, updates);

    return 0;
}
