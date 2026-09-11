// -------- list 赋值和交换 --------
/*
功能描述：
- 给list容器赋值以及交换list容器
函数原型：
- assign(beg, end);                     // 将[beg, end)区间 的数据拷贝赋值给本身
- assign(n, elem);                      // 将n个elem拷贝赋值给本身
- list& operator=(const list &list);    // 重载等号操作符
- swap(list);                           // 将list与本身元素互换
*/

#include <iostream>
#include <list>

void printList(const std::list<int>& l){
    for(std::list<int>::const_iterator it = l.begin(); it != l.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// 赋值
void test1(){
    std::list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printList(l1);

    std::list<int> l2;
    l2 = l1;  // operator =
    printList(l2);

    std::list<int> l3;
    l3.assign(l2.begin(), l2.end());
    printList(l3);

    std::list<int> l4;
    l4.assign(10, 100);
    printList(l4);    

}

// 交换
void test2(){
    std::list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    std::list<int> l2;
    l2.assign(10, 100);

    std::cout << "交换前: " << std::endl;
    printList(l1);
    printList(l2);

    l1.swap(l2);
    std::cout << "交换后: " << std::endl;
    printList(l1);
    printList(l2);

}

int main(){
    test1();
    test2();

    return 0;
}