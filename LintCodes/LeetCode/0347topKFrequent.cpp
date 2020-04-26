#include <unordered_map>
#include <queue>
#include <utility>

#include "LeetCode.h"
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
    vector<int> res;
    if (nums.empty()) {
        return res;
    }

    unordered_map<int, int> counter;
    for (auto i : nums) {
        counter[i]++;
    }
    auto cmp = [](pair<int,int>& p1, pair<int, int>& p2) ->bool { return p1.second < p2.second;};
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pque(cmp);

    for (auto i : counter)
    {
        pque.push(i);
    }
    for (int i = 0; i < k; ++i)
    {
        auto p = pque.top();
        pque.pop();
        res.push_back(p.first);
    }
    return res;
}

void test0347()
{
    vector<int> v{1, 2, 4, 6, 6, 1, 3, 4, 5, 3, 2, 1, 2};
    cout << "original array is :" << endl;
    displayArray(v, cout);
    auto rv = topKFrequent(v, 2);
    cout << "most frequnt 2 element: " << endl << rv[0] << '\t' << rv[1] << endl;

    cout << "test done" << endl;
}