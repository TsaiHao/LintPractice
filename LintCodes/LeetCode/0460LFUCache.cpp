#include <vector>
#include <utility>
#include <algorithm>

#include "LeetCode.h"
using namespace std;
class LFUCache {
public:
    using cache = pair<pair<int, int>, int>;
    LFUCache(int capacity): _capacity(capacity)
    {

    }
    
    int get(int key) 
    {
        for (auto iter = _cachePool.begin(); iter < _cachePool.end(); ++iter)
        {
            if (iter->first.first == key) {
                int ret = iter->first.second;
                ++(iter->second);
                auto c = *iter;
                auto pos = iter;
                while(pos >= _cachePool.begin())
                {
                    if (pos->second > iter->second) {
                        if (iter != pos + 1) {
                            _cachePool.erase(iter);
                            _cachePool.insert(pos + 1, c);
                        }
                        break;
                    }
                    if (pos == _cachePool.begin()) {
                        if (pos != iter) {
                            _cachePool.erase(iter);
                            _cachePool.insert(pos, c);
                        }
                        break;
                    }
                    --pos;
                }
                return ret;
            }
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if (_capacity == 0) {
            return;
        }
        for (auto i = _cachePool.begin(); i < _cachePool.end(); ++i)
        {
            if (i->first.first == key) {
                i->first.second = value;
                get(i->first.first);
                return;
            }
        }
        if (_cachePool.size() >= _capacity) {
            _cachePool.pop_back();
        }
        if (!_cachePool.empty()) {
            auto iter = _cachePool.end() - 1;
            while(iter->second == 0)
            {
                if (iter == _cachePool.begin()) {
                    break;
                }
                --iter;
            }
            if (iter->second == 0)
                _cachePool.insert(iter, {{key, value}, 0});
            else
            {
                _cachePool.insert(iter + 1, {{key, value}, 0});
            }
        }
        else {
            _cachePool.push_back({{key, value}, 0});
        }
    }
private:
    vector<cache> _cachePool;
    unsigned int _capacity;
};;