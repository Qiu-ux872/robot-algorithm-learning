// --------  list反转和排序 --------
/*
函数原型：
- reverse(); // 反转链表
- sort();    // 排序
*/
#include <iostream>
#include <algorithm>
#include <list>

void printList(const std::list<int> l){
    for(std::list<int>::const_iterator it = l.begin(); it != l.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test(){
    std::list<int> l;
    l.push_back(20);
    l.push_back(50);
    l.push_back(30);
    l.push_back(60);
    l.push_back(10);
    printList(l);
    std::cout << "排序后: " << std::endl;
    l.sort();
    printList(l);
    std::cout << "反转后: " << std::endl;
    l.reverse();
    printList(l);

}

int main(){
    test();

    return 0;
}