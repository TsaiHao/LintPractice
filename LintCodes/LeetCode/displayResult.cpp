#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "LeetCode.h"
using namespace std;

template <typename T, typename A>
void displayResult(ostream& os, T& result)
{
    if (typeid(T) == typeid(vector<vector<A>>)) {
        for (auto i = result.begin(); i != result.end(); ++i) {
            for (auto j = i->begin(); j != i->end(); ++j) {
                os << *j << '\t';
            }
            os << "\r\n";
        }
    }
}