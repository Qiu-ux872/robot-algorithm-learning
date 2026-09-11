// -------- set查找和统计 --------
/*
函数原型：
- find(key);    // 若存在返回该元素的迭代器；若不存在返回set.end()
- count(key);   // 统计key的个数  0或1
*/

#include <iostream>
#include <set>

void test(){
    std::set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(40);
    s1.insert(30);
    s1.insert(50);
    s1.insert(60);
    s1.insert(70);
    
    // 查找 使用迭代器接收
    std::set<int>::iterator pos = s1.find(30);
    if(pos != s1.end()){
        std::cout << "找到元素" << *pos << std::endl;
    } else {
        std::cout << "未找到元素" << std::endl;
    }

}

// 统计
void test2(){
    std::set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(40);
    s1.insert(30);
    s1.insert(50);
    s1.insert(60);
    s1.insert(70);

    int num = s1.count(10);
    std::cout << "num = " << num << std::endl;

}

int main(){
    test();
    test2();

    return 0;
}