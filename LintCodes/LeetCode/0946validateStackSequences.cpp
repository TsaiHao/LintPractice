#include <algorithm>
#include <stack>

#include "LeetCode.h"
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
{
    bool f = true;
    stack<int> pushStack, popStack;
    reverse(pushed.begin(), pushed.end());
    for (auto i = popped.rbegin(); i != popped.rend(); ++i) {
        popStack.push(*i);
    }
    while (!pushed.empty() && !popStack.empty())
    {
        if (!pushed.empty()) {
            pushStack.push(pushed.back());
            pushed.pop_back();
        }
        while (!popStack.empty() && !pushStack.empty() && popStack.top() == pushStack.top()) {
            pushStack.pop();
            popStack.pop();
        }
        if (!pushStack.empty() && popStack.top() != pushStack.top() && pushed.empty()) {
            return false;
        }
    }
    if (pushStack.empty()) {
        return true;
    }
    return false;
}