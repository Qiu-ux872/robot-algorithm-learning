// -------- set插入和删除 --------
/*
函数原型：
- insert(elem);
- clear();
- erase(pos);  // pos--->interator
- erase(beg, end);  // [beg, end)
- erase(elem);
*/

#include <iostream>
#include <set>

void prinSet(const std::set<int>& s){
    for(std::set<int>::const_iterator it = s.begin(); it != s.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test(){
    std::set<int> s1;

    // 插入
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    prinSet(s1);

    // 删除
    s1.erase(s1.begin());
    prinSet(s1);

    // 删除重载版本
    s1.erase(30);
    prinSet(s1);

    // 清空
    s1.clear();
    // s1.erase(s1.begin(), s1.end()); 也可以清空

}

int main(){
    test();
    
    return 0;
}