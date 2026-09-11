// -------- set构造和赋值 --------
/*
函数：
- set<T> st;
- set(const set &st);
- set& operator=(const set& st); 
*/

#include <iostream>
#include <set>

void printSet(const std::set<int>& s){
    for(std::set<int>::const_iterator it = s.begin(); it != s.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test(){
    std::set<int> s1;

    // 插入数据只有insert
    s1.insert(10);
    s1.insert(30);
    s1.insert(30);
    s1.insert(40);
    s1.insert(20);
    // 输出后会自动生序 并去掉重复元素只保留一个
    printSet(s1);

    // 拷贝构造
    std::set<int> s2(s1);
    printSet(s2);

    // 赋值操作
    std::set<int> s3;
    s3 = s2;
    printSet(s3);

}

int main(){
    test();

    return 0;
}