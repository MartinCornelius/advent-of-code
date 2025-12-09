#include <bits/stdc++.h>

using namespace std;

void part1(const vector<pair<long long, long long>> ranges)
{
    long long result = 0;

    string tmp;
    for (auto &pair : ranges)
    {
        for (long long num = pair.first; num <= pair.second; num++)
        {
            tmp = to_string(num);
            string a = tmp.substr(0, tmp.length() / 2);
            string b = tmp.substr(tmp.length() / 2);

            if (tmp.length() > 1 && tmp.length() % 2 == 0 && a == b) result += num;
        }
    }

    cout << "part 1: " << result << endl;
}

void part2()
{
}

int main()
{
    string line; getline(cin, line);
    vector<pair<long long, long long>> ranges;

    vector<int> startPositions;
    // Get all the start positions
    startPositions.push_back(-1);
    size_t pos = line.find(",");
    while (pos != string::npos)
    {
        startPositions.push_back(pos);
        pos = line.find(",", pos + 1);
    }

    long long a, b;
    for (auto &pos : startPositions)
    {
        int delimiterIdx = line.find("-", pos + 1);
        try 
        {
            a = stoll(line.substr(pos + 1, delimiterIdx - pos - 1));
            b = stoll(line.substr(delimiterIdx + 1, line.find(",", delimiterIdx) - delimiterIdx - 1));
            ranges.push_back({a, b});
        }
        catch (const std::out_of_range& e)
        {
            cout << pos;
            cerr << "\tOut of range error: " << e.what() << endl;
        }
        catch (const std::invalid_argument& e) {
            cerr << "Invalid argument error: " << e.what() << endl;
        }
    }

    part1(ranges);
}
