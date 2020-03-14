#include <future>
#include <iostream>

#include "LeetCode.h"
using namespace std;

class Foo {
public:
    Foo() {
        f1 = prom1.get_future();
        f2 = prom2.get_future();
    }
    promise<int> prom1, prom2;
    future<int> f1, f2;
    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        prom1.set_value(1);
    }

    void second(function<void()> printSecond) {
        f1.get();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        prom2.set_value(2);
    }

    void third(function<void()> printThird) {
        f2.get();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};