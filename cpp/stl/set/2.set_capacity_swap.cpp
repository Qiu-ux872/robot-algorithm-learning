// -------- set容器大小和交换 --------
/*
函数原型：
- size();
- empty();
- swap();
!!!!! 不允许重新指定大小 !!!!!
*/

#include <iostream>
#include <set>

void printSet(const std::set<int> s){
    for(std::set<int>::const_iterator it = s.begin(); it != s.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void  test1(){
    std::set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    if(s1.empty()){
        std::cout << "s1为空" << std::endl;
    } else {
        std::cout << "s1不为空" << std::endl;
        std::cout << "s1大小为: " << s1.size() << std::endl;
    }

}

void test2(){
    std::set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    std::set<int> s2;
    s2.insert(100);
    std::cout << "交换前: " << std::endl;
    printSet(s1);
    printSet(s2);

    s1.swap(s2);
    std::cout << "交换后: " << std::endl;
    printSet(s1);
    printSet(s2);

}

int main(){
    test1();
    test2();

    return 0;
}