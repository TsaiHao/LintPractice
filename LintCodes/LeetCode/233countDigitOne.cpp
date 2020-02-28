
#include "LeetCode.h"
using namespace std;

int countDigitOne(int n)
{
	if (n < 0) {
		return 0;
	}
	int icount = 0, N = n;;
	int x = 1;

	while (n != 0) {
		int last = n % 10;
		if (last == 1) {
			icount += (N / 10 / x) * x + (N % x + 1);
		}
		else if (last == 0) {
			icount += (N / 10 / x) * x;
		}
		else {
			icount += (N / 10 / x + 1) * x;
		}
		if (x == 1000000000) {
			break;
		}
		x *= 10;
		n /= 10;
	}
	return icount;
}