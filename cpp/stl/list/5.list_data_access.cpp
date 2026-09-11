// -------- list数据存取 --------
/*
函数原型：
- front();
- back();
!!!!! list 不支持[]和at()访问 !!!!!
*/

#include <iostream>
#include <list>

void test(){
    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);

    std::cout << "l的队首元素: " << l.front() << std::endl;
    std::cout << "l的队尾元素: " << l.back() << std::endl;

    // 验证迭代器不支持随机访问
    std::list<int>::iterator it = l.begin();
    it++;
    it--;
    // it = it + 1; 会报错 不允许跳跃式访问 只允许双向逐个元素访问

}

int main(){
    test();

    return 0;
}