#include <sstream>
#include "LeetCode.h"
using namespace std;

// wait to finish
int numDupDigitsAtMostN(int N)
{
    if (N < 11) {
        return 0;
    }
    bool used[10] = {false};
    int lastBits = 10;

    stringstream sstr;
    sstr << N;
    string num = sstr.str();
    int digits = 0;
    for (auto iter = num.begin(); iter != num.end(); ++iter)
    {
        int bits = num.end() - iter;
        int cur = *iter - '0';
        int firstChoice = cur;
        for (int i = cur; i >= 0; --i) {
            if (used[i]) {
                --firstChoice;
            }
        }
        int choice = lastBits;
        for (int i = bits; i > 0; --i) {
            firstChoice *= --choice;
        }
        digits += firstChoice;
        if (!used[cur]) {
            --lastBits;
            used[cur] = true;
        }
    }
    return digits;
}