#include <string>
#include <algorithm>

#include "LeetCode.h"
using namespace std;

string longestPalindrome(string s, int i)
{
    if (s.size() < 2) {
        return s;
    }
    if (s.size() == 2) {
        return ((s[0] == s[1]) ? s: string(1, s[0]));
    }
    string longest;
    for (int n = 0; n < s.size(); ++n)
    {
        auto left = s.begin() + n;
        auto right = left;
        while(left >= s.begin() && right < s.end())
        {
            if (*left != *right) {
                ++left;
                --right;
                break;
            }
            else {
                if (left == s.begin() || right == s.end() - 1) {
                    break;
                }
                --left;
                ++right;
            }   
        }
        if (right - left + 1 > longest.size()) {
            longest = string(left, right + 1);
        }

        left = s.begin() + n;
        right = left + 1;
        while(left >= s.begin() && right < s.end())
        {
            if (*left != *right) {
                ++left;
                --right;
                break;
            }
            else {
                if (left == s.begin() || right == s.end() - 1) {
                    break;
                }
                --left;
                ++right;
            }  
        }
        if (right - left + 1 > longest.size()) {
            longest = string(left , right + 1);
        }
    }
    return longest;
}