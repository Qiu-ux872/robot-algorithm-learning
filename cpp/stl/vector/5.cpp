// -------- vector数据存取 --------
/*
功能描述：
- 对vector中的数据的存取操作
函数原型：
- at(int idx);          // 返回索引idx所指的数据
- operator[];           // 返回索引idx所指的数据
- front();              // 返回容器中的第一个数据元素
- back();               // 返回容器中最后一个数据元素
*/

#include <iostream>
#include <vector>

void test(){
    std::vector<int> v1;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }

    // 利用[]访问数组元素
    for(int i = 0; i < v1.size(); i++){
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;

    // 利用at访问元素
    for(int i = 0; i < v1.size(); i++){
        std::cout << v1.at(i) << " ";
    }
    std::cout << std::endl;

    // 获取第一个元素
    std::cout << "第一个元素为:" << v1.front() << std::endl;

    // 获取最后一个元素
    std::cout << "最后一个元素为:" << v1.back() << std::endl;

}

int main(){
    test();

    return 0;
}