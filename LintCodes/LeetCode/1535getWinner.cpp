#include <algorithm>
#include <vector>
#include <iostream>
#include "LeetCode.h"
using namespace std;

int getWinner(vector<int>& arr, int k) {
    if (k >= arr.size() - 1) {
        return *(max_element(arr.begin(), arr.end()));
    }
    auto iter = arr.begin();
    while (iter != arr.end()) {
        int x = *iter;
        int ek = 0;
        if (arr.end() - iter - 1 < k) {
            ek = arr.end() - iter - 1;
        }
        else {
            ek = (iter == arr.begin() ? k: k - 1);
        }
        bool found = true;
        for (int i = 0; i < ek; ++i) {
            ++iter;
            if (*iter > x) {
                found = false;
                break;
            }
        }
        if (found) {
            return x;
        }
    }
    return 0;
}