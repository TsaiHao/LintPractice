#include <algorithm>

#include "LeetCode.h"
using namespace std;

int rangeBitwiseAnd(int m, int n)
{
    if (((m & 0x01) == 0 && m + 1 == n) || m == n) {
        return m;
    }
    if ((m & (1 << 31)) == 0 && (m << 1) <= n) {
        return 0;
    }
    if (m == 0) {
        return 0;
    }
    int bit = 1;
    while (bit < n) {
        bit <<= 1;
    }
    if (bit != n) {
        bit >>= 1;
    }
    if ((m & n & bit) == 0) {
        return 0;
    }
    int mask = ~bit;
    return bit | rangeBitwiseAnd(m & mask, n & mask);
}