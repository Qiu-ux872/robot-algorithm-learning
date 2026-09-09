// -------- deque插入和删除 ---------
/*
功能描述：
- 向deque容器中插入和删除数据
函数原型：
- 1、两端插入操作：
    - push_back(elem);         // 在容器尾部插入elem
    - push_front(elem);        // 在容器头部插入elem
    - pop_back();              // 删除容器最后一个数据
    - pop_front();             // 删除容器第一个数据

- 2、指定位置操作：
    - insert(pos, elem);        // 在pos位置插入一个elem元素的拷贝，返回新数据的位置
    - insert(pos, n, elem);     // 在pos位置插入n个elem数据，无返回值
    - insert(pos, beg, end);    // 在pos位置插入[beg, end)区间的数据，无返回值
    - clear();                  // 清空容器内所有数据
    - erase(beg, end);          // 删除[beg, end)区间的数据，返回下一个数据的位置
    - erase(pos);               // 删除pos位置的数据，返回下一个数据的位置
*/

#include <iostream>
#include <deque>

void printDeque(const std::deque<int> d){
    for(std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// 两端操作
void test1(){
    std::deque<int> d1;
    
    // 尾插
    d1.push_back(10);
    d1.push_back(20);

    // 头插
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);

    // 尾删
    d1.pop_back();
    printDeque(d1);

    // 头删
    d1.pop_front();
    printDeque(d1);
}

// 指定位置
void test2(){
    std::deque<int> d1;
    
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);

    // insert插入
    d1.insert(d1.begin(), 1000);
    // 1000 200 100 10 20
    printDeque(d1);

    d1.insert(d1.begin(), 2, 10000);
    // 10000 10000 1000 200 100 10 20
    printDeque(d1);

    // 按照区间插入
    std::deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d1.insert(d1.begin(), d2.begin(), d2.end());
    // 1 2 3 10000 10000 1000 200 100 10 20
    printDeque(d1);

}

void test3(){
    std::deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);

    // 删除
    // 定义迭代器从而进行指定位置删除
    std::deque<int>::iterator it = d1.begin();
    it++; // 指定为头部后一位
    d1.erase(it);
    printDeque(d1);

    // 按区间删除
    d1.erase(d1.begin(), d1.end());
    // d1.clear(); 也是清除
    printDeque(d1);
}

int main(){
    test1();
    std::cout << "------------------------------" << std::endl;
    test2();
    std::cout << "------------------------------" << std::endl;
    test3();

    return 0;
}