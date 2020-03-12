#include "LeetCode.h"

int numWays(int n) {
    int a = 1, b = 1;
    for (int i = 2; i <= n; ++i) {
        int tmp = a;
        a = (a % int(1e9 + 7) + b % int(1e9 + 7)) % int(1e9 + 7);
        b = tmp;
    }
    return a;
}