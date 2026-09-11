// 对组 ---> 成对出现的数据，利用对组可以返回两个数据
/*
两种创建方式：
- pair<type, type> p (value1, value2);
- pair<type, type> p = make_pair(value1, value2)
*/

#include <string>
#include <iostream>
#include <utility>

void test(){
    // pair对组的创建
    // 第一种方式
    std::pair<std::string, int> p("Tom", 18);

    std::cout << "姓名: " << p.first << " 年龄: " << p.second << std::endl;

    // 第二种方式
    std::pair<std::string, int> p2("Jerry", 20);
    std::cout << "姓名: " << p2.first << " 年龄: " << p.second << std::endl;

}

int main(){
    test();

    return 0;
}