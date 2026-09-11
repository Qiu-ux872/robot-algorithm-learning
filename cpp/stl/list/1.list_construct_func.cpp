// -------- list构造函数 --------
/*
功能描述：
- 创建list容器
函数原型：
- list<T> lst;
- list(beg, end);
- list(n, elem);
- list(const list &lst);
*/

#include <iostream>
#include <list>

void printList(const std::list<int>& l){
    for(std::list<int>::const_iterator it = l.begin(); it != l.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test(){
    std::list<int> l1;
    
    // 默认构造
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    // 遍历容器
    printList(l1);

    // 按照区间构造
    std::list<int> l2(l1.begin(), l1.end());
    printList(l2);

    // 拷贝构造
    std::list<int> l3(l2);
    printList(l3);

    // n个elem
    std::list<int> l4(10, 1000);
    printList(l4);

}

int main(){
    test();

    return 0;
}