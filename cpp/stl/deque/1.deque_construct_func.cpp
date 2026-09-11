// -------- deque构造函数 --------
/*
功能描述：
- deque容器构造
函数原型：
- deque<T> deqT;                // 默认构造形式
- deque(beg, end);              // 构造函数将[beg, end)区间中的元素拷贝给本身
- deque(n, elem);               // 构造函数将n个elen拷贝给本身
- deque(const deque &deq);      // 拷贝构造函数
*/

#include <iostream>
#include <deque>

// 加上const使得形参只读的情况下迭代器不能用iterator而用const_interator
void printDeque(const std::deque<int>& d){
    for(std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test(){
    std::deque<int> d1;
    for(int i = 0; i < 10; i++){
        d1.push_back(i);
    }
    printDeque(d1);

    std::deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);

    std::deque<int> d3(10, 100);
    printDeque(d3);

    std::deque<int> d4(d3);
    printDeque(d4);

}

int main(){
    test();

    return 0;
}