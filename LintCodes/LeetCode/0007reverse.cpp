#include <limits.h>
#include <math.h>

#include "LeetCode.h"
using namespace std;
const int MULTILIMIT = INT32_MAX / 10;

int reverse(int x)
{
    int rev = 0;
    int symb = (x < 0 ? -1 : 1);
    if (x == INT32_MIN) {
        return 0;
    }
    x = abs(x);
    if (x > int(1e9) && x % 10 > 2) {
        return 0;
    }
    const int tailLimit = (symb == -1 ? 8 : 7);
    while (x != 0)
    {
        if (rev > MULTILIMIT) {
            return 0;
        }
        if (rev == MULTILIMIT) {
            if (x % 10 > tailLimit) {
                return 0;
            }
        }
        rev *= 10;
        rev += x % 10;
        x /= 10;
    }

    return symb * rev;
}

void test0007()
{
    cout << "testing 0007 reverse: " << endl
        << "input an integer:" << endl;
    int x;
    while (cin >> x) {
        cout << "you input :" << x << endl;
        cout << "It's reverse is: " << reverse(x) << endl;
    }
    cout << "test done" << endl;
}