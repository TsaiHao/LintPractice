#include <sstream>
#include <string>
#include <algorithm>

#include "LeetCode.h"
using namespace std;

string itostring(int i)
{
    string ret("");
    if (i < 0) {
        i = -i;
        ret.push_back('-');
    }
    do {
        ret.push_back(i % 10 + '0');
        i /= 10;
    } while(i != 0);
    return string(ret.rbegin(), ret.rend());
}

string compressString(string S)
{
    if (S.size() <= 2) {
        return S;
    }

    string ret("");
    char lastLetter = 0;
    size_t cur_len = 0;
    string tmp;
    for (auto iter = S.begin(); iter != S.end(); ++iter) {
        if (*iter != lastLetter) {
            if (lastLetter != 0) {
                ret += itostring(cur_len);
            }
            ret.push_back(*iter);
            lastLetter = *iter;
            cur_len = 1;
        }
        else {
            ++cur_len;
        }
    }
    if (cur_len != 0) {
        ret += itostring(cur_len);
    }
    return (S.size() > ret.size() ? ret : S);
}