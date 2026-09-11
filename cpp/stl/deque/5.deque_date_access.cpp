// -------- deque数据存取 --------
/*
功能描述：
- 对duque中的数据存取操作
函数原型：
- at(int idx);      // 返回索引idx所指的数据
- operator[];       // 返回索引idx所指的数据
- front();          // 返回容器中第一个数据元素
- back();           // 返回容器中最后一个数据元素
*/

#include <iostream>
#include <deque>

void printDeque(const std::deque<int> d){
    for(std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test01(){
    std::deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);

    // 通过[]访问元素
    // 300 200 100 10 20 30
    for(int i = 0; i < d.size(); i++){
        std::cout << d[i] << " ";
    }
    std::cout << std::endl;

    // 通过at方式访问元素
    for(int i = 0; i < d.size(); i++){
        std::cout << d.at(i) << " ";
    }
    std::cout << std::endl;

    // 访问头尾元素
    std::cout << "第一个元素: " << d.front() << std::endl;
    std::cout << "最后一个元素: " << d.back() << std::endl;

}

int main(){
    test01();

    return 0;
}