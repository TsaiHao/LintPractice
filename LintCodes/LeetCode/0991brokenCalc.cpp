#include <algorithm>

#include "LeetCode.h"
using namespace std;

int brokenCalc(int X, int Y)
{
    if (X >= Y)
    {
        return X - Y;
    }

    int p = Y;
    int length = 0;
    while (p > X)
    {
        length += 1 + p & 1;
        p = (p + 1) >> 1;
    }
    
    return length + X - p;
}