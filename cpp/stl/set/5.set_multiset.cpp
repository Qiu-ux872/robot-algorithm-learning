// -------- set和multiset区别 --------

#include <iostream>
#include <set>
#include <utility>

void test(){
    std::set<int> s;
    std::pair<std::set<int>::iterator, bool> res = s.insert(10);
    if(res.second){
        std::cout << "第一次出入成功" << std::endl;
    } else {
        std::cout << "第一次插入失败" << std::endl;
    }

    s.insert(10);
    std::pair<std::set<int>::iterator, bool> res1 = s.insert(10);
    if(res1.second){
        std::cout << "第二次出入成功" << std::endl;
    } else {
        std::cout << "第二次插入失败" << std::endl;
    }

    std::multiset<int> ms;  // 允许插入重复的值
    ms.insert(10);  // 返回迭代器 不会判断是否成功
    ms.insert(10);
    ms.insert(20);
    ms.insert(10);
    for(std::multiset<int>::iterator it = ms.begin(); it != ms.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

}

int main(){
    test();

    return 0;
}