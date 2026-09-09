// -------- vector互换容器 --------
/*
功能描述：
- 实现两个容器内元素进行互换
函数原型：
- swap(vec);   // 将vec与本身的元素互换
*/

#include <iostream>
#include <vector>

void printVector(std::vector<int>& v){
    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// 基本使用
void test(){
    std::vector<int> v1;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    printVector(v1);

    std::vector<int> v2;
    for(int i = 10; i > 0; i--){
        v2.push_back(i);
    }
    printVector(v2);

    std::cout << "交换后: " << std::endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);

}

// 实际用途
// 巧用swap可以收缩内存空间
void test02(){
    std::vector<int> v;
    for(int i = 0; i < 100000; i++){
        v.push_back(i);
    }
    std::cout << "v的容量: " << v.capacity() << std::endl;
    std::cout << "v的大小: " << v.size() << std::endl;
    std::cout << std::endl;

    // 重新制定大小
    v.resize(3);
    std::cout << "v的容量: " << v.capacity() << std::endl; // 130000
    std::cout << "v的大小: " << v.size() << std::endl;     // 3
    std::cout << std::endl;

    // 用swap收缩内存
    // std::vector<int>(v) 匿名对象 按照目前v的大小初始化匿名对象
    // 系统会回收匿名对象的资源并释放
    std::vector<int>(v).swap(v);
    std::cout << "v的容量: " << v.capacity() << std::endl; // 3
    std::cout << "v的大小: " << v.size() << std::endl;     // 3

}


int main(){
    test();
    test02();

    return 0;
}