#include <string>
#include <climits>
#include <algorithm>

#include "LeetCode.h"
using namespace std;

int tenthMax = INT_MAX / 10;
inline bool isDigit(const char c)
{
    return c >= '0' && c <= '9';
}
inline int ctoi(const char c, bool neg = false)
{
    return (c - '0') * (neg ? -1 : 1);
}
inline bool willOverflow(int now, const char toAdd, const bool neg)
{
    if (now > tenthMax || now < -tenthMax) {
        return true;
    }
    if (now < tenthMax && now > -tenthMax) {
        return false;
    }
    int thres = neg ? '8' : '7';
    return toAdd > thres;
}

int myAtoi(string str)
{
    int ret = 0;
    int bits = 0;
    auto iter = str.begin();

    for (; iter != str.end(); ++iter) {
        if (*iter == '+' || *iter == '-' || isDigit(*iter)) {
            break;
        }
        if (*iter == ' ') {
            continue;
        }
        else {
            return 0;
        }
    }
    if (iter == str.end()) {
        return 0;
    }

    bool neg = (*iter == '-' ? true : false); 
    if (!isDigit(*iter))
        ++iter;
    for (; iter != str.end() && isDigit(*iter); ++iter) {
        if (ret == 0) {
            ret += ctoi(*iter);
            ret *= (neg ? -1 : 1);
            continue;
        }
        if (willOverflow(ret, *iter, neg)) {
            return neg ? INT_MIN : INT_MAX;
        }
        ret *= 10;
        ret += ctoi(*iter, neg);
    }
    return ret;
}