// -------- list 容器大小操作 --------
/*
函数原型：
- size();
- empty();
- resize(num);
- resize(num, elem);
*/

#include <iostream>
#include <list>

void printList(const std::list<int> l){
    for(std::list<int>::const_iterator it = l.begin(); it != l.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test(){
    std::list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    printList(l1);
    // 判断是否为空
    if(l1.empty()){
        std::cout << "l1为空";
    } else {
        std::cout << "l1不为空" << std::endl;
        std::cout << "l1元素个数: " << l1.size() << std::endl;
    }
    l1.resize(10, 10);
    printList(l1);

}

int main(){
    test();

    return 0;
}