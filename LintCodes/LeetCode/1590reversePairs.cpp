#include <algorithm>
#include <map>
#include <cstring>
#include <set>
#include <unordered_map>

#include "LeetCode.h"
using namespace std;
typedef vector<int>::iterator vit;

//Merge Implementation
int merge_pairs(const vit left, const vit mid, const vit right)
{
    auto lIter = left, rIter = mid;
    int pairs = 0;
    vector<int> temp;
    while (lIter != mid && rIter != right)
    {
        if (*lIter <= *rIter) {
            temp.push_back(*(lIter++));
        }
        else {
            pairs += mid - lIter;
            temp.push_back(*(rIter++));
        }
    }
    while (lIter != mid) 
    {
        temp.push_back(*(lIter++));
    }
    //pairs += right - rIter;
    while (rIter != right)
    {
        temp.push_back(*(rIter++));
    }
    copy(temp.begin(), temp.end(), left);
    return pairs;
}

int countReversePairs(const vit left, const vit right)
{
    if (right - left <= 1) {
        return 0;
    }
    vit mid = left + (right - left) / 2;
    int left_pairs = countReversePairs(left, mid);
    int right_pairs = countReversePairs(mid, right);
    
    int splitPairs = left_pairs + right_pairs;
    if (*(mid - 1) <= *mid) {
        return splitPairs;
    }
    return splitPairs + merge_pairs(left, mid, right);
}

//Tree Array Implementation
class treeArray
{
public:
    explicit treeArray(size_t size): size(size)
    {
        __array = new int[size + 1];
        memset(__array, 0, sizeof(int) * (size + 1));
    }
    ~treeArray()
    {
        delete[] __array;
    }

    void update(size_t index, const int delta)
    {
        while (index <= size)
        {
            *(__array + index) += delta;
            index += lower_bit(index);
        }
    }

    int getSum(size_t index)
    {
        int res = 0;
        while (index > 0)
        {
            res += *(__array + index);
            index -= lower_bit(index);
        }
        return res;
    }
private:
    size_t size;
    int* __array;
    inline size_t lower_bit(int x)
    {
        return x & (-x);
    }
};

int treeCountReversePairs(vector<int>& nums)
{
    if (nums.size() <= 1) {
        return 0;
    }
    set<int> numSet(nums.begin(), nums.end());
    unordered_map<int, size_t> nToIndex;
    size_t index = 1;
    for (auto iter = numSet.begin(); iter != numSet.end(); ++iter)
    {
        nToIndex[*iter] = index++;
    }
    treeArray tr(numSet.size());

    int total = 0;
    for (auto rIter = nums.rbegin(); rIter != nums.rend(); ++rIter)
    {
        size_t query = nToIndex[*rIter];
        tr.update(query, 1);
        total += tr.getSum(query - 1);
    }
    return total;
}

int reversePairs(vector<int>& nums)
{
    return treeCountReversePairs(nums);
    //return countReversePairs(nums.begin(), nums.end());
}