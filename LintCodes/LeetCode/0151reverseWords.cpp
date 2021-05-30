#include <algorithm>
#include "LeetCode.h"

using namespace std;

string reverseWords(string s) {
    reverse(s.begin(), s.end());
    bool prevSpace = true;
    for (auto iter = s.begin(); iter != s.end();) {
        if (*iter == ' ' && prevSpace) {
            auto si = iter;
            while (si != s.end() && *si == ' ') {
                ++si;
            }
            iter = s.erase(iter, si);
            if (iter == s.end()) {
                break;
            }
            prevSpace = false;
        } else if (*iter == ' ') {
            ++iter;
            prevSpace = true;
            continue;
        }
        auto word = iter;
        while (word != s.end() && *word != ' ') {
            ++word;
        }
        reverse(iter, word);
        iter = word;
        prevSpace = false;
    }
    if (!s.empty()) {
        while (s.back() == ' ') {
            s.pop_back();
        }
    }
    return s;
}