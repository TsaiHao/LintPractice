#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> _left;
    priority_queue<int, vector<int>, greater<int>> _right;
    size_t _size;
public:
    MedianFinder(): _size(0) {

    }
    
    void addNum(int num) {
        if ((_size & 0x01) == 0)
        {
            _left.push(num);
        }
        else 
        {
            _right.push(num);
        }
        ++_size;
        if (_left.empty() || _right.empty()) {
            return;
        }
        if (_left.top() > _right.top())
        {
            int l = _left.top(), r = _right.top();
            _left.pop();
            _right.pop();
            _left.push(r);
            _right.push(l);
        }
    }
    
    double findMedian() {
        if (_size == 0) {
            return -1;
        }
        if ((_size & 0x01) == 0)
        {
            return (double)(_left.top() + _right.top()) / 2.0;
        }
        else 
        {
            return (_left.size() > _right.size() ? _left.top() : _right.top());
        }
    }
};