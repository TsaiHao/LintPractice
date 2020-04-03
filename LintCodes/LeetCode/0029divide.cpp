#include <iostream>
#include <math.h>
#include <limits.h>
#include "LeetCode.h"

unsigned int BitmoveDivide(unsigned int dividend, unsigned int divisor)
{
    if (dividend == divisor) {
        return 1;
    }
    if (dividend < divisor) {
        return 0;
    }
    unsigned int rightMoveStep = 0;
    unsigned int divAfterMove = dividend;
    while (divAfterMove > divisor) {
        divAfterMove >>= 1;
        rightMoveStep++;
    }
    --rightMoveStep;
    int resdual = dividend - (divisor << rightMoveStep);
    return (1 << rightMoveStep) + BitmoveDivide(resdual, divisor);
}

int divide(int dividend, int divisor) {
    const unsigned int absMin = 0x80000000;

    if (divisor == 0 || dividend == 0) {
        return 0;
    }
    if (divisor == 1) {
        return dividend;
    }
    if (dividend == INT_MIN && divisor == -1)
    {
        return INT_MAX;
    }
    bool dividendPosi = (dividend > 0), divisorPosi = (divisor > 0);
    unsigned int absDividend = (dividend == INT_MIN) ? absMin : abs(dividend);
    unsigned int absDivisor = (divisor == INT_MIN) ? absMin : abs(divisor);
    unsigned int x = BitmoveDivide(absDividend, absDivisor);

    return ((dividendPosi && divisorPosi || !(dividendPosi || divisorPosi)) ? x : -x);
}