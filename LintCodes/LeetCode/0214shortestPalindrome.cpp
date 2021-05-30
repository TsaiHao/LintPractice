#include <algorithm>

#include "LeetCode.h"
using namespace std;

int getInsideLength(string& s)
{
    size_t N = s.size();
    bool split = ~(N & 0x01);
    int left = (N - 1) >> 1, right = N >> 1;
    bool isPalind;
    int lcopy, rcopy;
    while (left >= 0)
    {
        isPalind = true;
        lcopy = left; rcopy = right;
        while (lcopy >= 0) {
            if (s[lcopy] != s[rcopy]) {
                isPalind = false;
                break;
            }
            lcopy--; rcopy++;
        }
        if (isPalind) {
            return left + right + 1;
        }
        if (split) {
            --left;
        }
        else {
            --right;
        }
        split = !split;
    }
    return 1;
}
string shortestPalindrome(string s)
{
    if (s.size() < 2) {
        return s;
    }
    size_t N = s.size();
    int len = 1;
    bool split = ~(N & 0x01);
    int left = (N - 1) >> 1, right = N >> 1;
    bool isPalind;
    int lcopy, rcopy;
    while (left >= 0)
    {
        isPalind = true;
        lcopy = left; rcopy = right;
        while (lcopy >= 0) {
            if (s[lcopy] != s[rcopy]) {
                isPalind = false;
                break;
            }
            lcopy--; rcopy++;
        }
        if (isPalind) {
            len = left + right + 1;
            break;
        }
        if (split) {
            --left;
        }
        else {
            --right;
        }
        split = !split;
    }
    string palind = string(s.rbegin(), s.rbegin() + (N - len)) + s;
    return palind;
}