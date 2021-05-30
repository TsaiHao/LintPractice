#include <algorithm>
#include <unordered_map>

#include "LeetCode.h"
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    vector<vector<string>> result;
    if (strs.empty())
    {
        return result;
    }

    unordered_map<string, vector<string>> dict;
    for (auto& s: strs)
    {
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        auto iter = dict.find(sorted);
        if (iter == dict.end()) {
            dict[sorted] = vector<string>();
            dict[sorted].push_back(s);
        }
        else {
            iter->second.push_back(s);
        }
    }

    for (auto i = dict.begin(); i != dict.end(); ++i) {
        result.push_back(i->second);
    }
    return result;
}