#include <vector>
#include <string>
#include <map>
#include <unordered_map>

#include "LeetCode.h"
using namespace std;
/*
// time out
vector<int> findSubstring(string s, vector<string>& words)
{
    if (s.empty() || words.empty())
    {
        return vector<int>();
    }
    int len = words[0].size(), Len = len * words.size();
    multimap<string, int> dict;
    for (auto w: words)
    {
        dict.insert({w, -1});
    }
    vector<int> ret;
    string tmp;

    for (int i = 0; i <= (int)s.size() - Len; ++i)
    {
        bool flag = true;
        for (auto iter = s.begin() + i; iter < s.begin() + i + Len; iter += len)
        {
            tmp = string(iter, iter + len);
            int count = dict.count(tmp);
            if (count == 0) 
            {
                flag = false;
                break;
            }
            auto pos = dict.find(tmp);
            bool isAllUsed = true;
            while(count)
            {
                if (pos->second != i) 
                {
                    pos->second = i;
                    isAllUsed = false;
                    break;
                }
                ++pos;
                --count;
            }
            if (isAllUsed)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ret.push_back(i);
        }
    }
    return ret;
}
*/

vector<int> findSubstring(string s, vector<string>& words)
{
    if (s.empty() || words.empty())
    {
        return vector<int>();
    }
    int len = words[0].size(), Len = len * words.size();
    unordered_map<string, int> dict;
    for (auto w: words)
    {
        auto p = dict.find(w);
        if (p == dict.end())
        {
            dict[w] = 1;
        }
        else 
        {
            dict[w]++;
        }
    }
    vector<int> ret;
    string tmp;
    unordered_map<string, int> dictCopy;

    for (int i = 0; i <= (int)s.size() - Len; ++i)
    {
        bool flag = true;
        dictCopy = dict;
        for (auto iter = s.begin() + i; iter < s.begin() + i + Len; iter += len)
        {
            tmp = string(iter, iter + len);
            auto pos = dictCopy.find(tmp);
            if (pos == dictCopy.end()) 
            {
                flag = false;
                break;
            }
            --(pos->second);
            if (pos->second < 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ret.push_back(i);
        }
    }
    return ret;
}