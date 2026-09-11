// -------- set容器排序 --------
/*
主要技术点：利用仿函数可以改变排序规则
*/

#include <iostream>
#include <set>

class MyCompare{
public:
    bool operator()(int v1, int v2) const {
    // 两个()不同含义-->第一个代表要重载的符号；第二个代表重载的函数体的参数列表
        return v1 > v2;
    }
};


void test(){
    std::set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(50);
    s1.insert(30);

    for(std::set<int>::iterator it = s1.begin(); it != s1.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 指定排序规则为降序
    std::set<int, MyCompare> s2;  // 在插入数据前声明排序规则

    s2.insert(10);
    s2.insert(40);
    s2.insert(20);
    s2.insert(50);
    s2.insert(30);

    // 遍历时类型要统一
    for(std::set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

}

int main(){
    test();

    return 0;
}