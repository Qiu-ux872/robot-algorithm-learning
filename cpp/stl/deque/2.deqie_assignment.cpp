// -------- deque赋值操作 --------
/*
功能描述：
- 给deque容器赋值
函数原型：
- deque& operator = (const deque %deq);    // 重载等号操作符
- assign(beg, end);                        // 将[beg, end)区间的数据拷贝赋值给本身
- assign(n, elem);                         // 将n个elem拷贝赋值给本身
*/

#include <iostream>
#include <deque>

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

    // 等号赋值 ----> operator=
    std::deque<int> d2;
    d2 = d1;
    printDeque(d2);

    // assign 赋值
    std::deque<int> d3;
    d3.assign(d1.begin(), d1.end());
    printDeque(d3);

    std::deque<int> d4;
    d4.assign(10, 100);
    printDeque(d4);


}

int
main(){
    test();

    return 0;
}