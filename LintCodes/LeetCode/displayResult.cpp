#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "LeetCode.h"
using namespace std;

template <typename T>
void displayMatrix(const vector<vector<T>>& mat, ostream& os)
{
    for (auto& arr : mat) {
        displayArray(arr, os);
    }
}

template <typename T>
void displayArray(const vector<T>& arr, ostream& os)
{
    for (auto& e : arr) {
        os << e << '\t';
    }
    os << endl;
}