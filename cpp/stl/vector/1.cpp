// -------- vector 构造函数 --------
/*
功能描述：
- 创建vector容器
函数原型：
- vector<T> v;                  // 采用模板实现类实现，默认构造函数
- vector(v.begin(), v.end())    // 将v[v.begin(), end()] 区间中的元素拷贝给本身
- vector(n, elem);              // 构造函数将n个elem拷贝给本身
- vector(const vector &vec);    // 拷贝构造函数
*/

#include <iostream>
#include <vector>

void printVector(std::vector<int>& v){
    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// vector容器构造
void test1(){
    std::vector<int> v1;  // 默认构造 无参构造
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    } 
    printVector(v1);

    // 通过区间方式构造
    std::vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    // n个elem方式构造
    std::vector<int> v3(10, 100); // 个数 值
    printVector(v3);

    // ------ 常用 ------
    // 拷贝构造
    std::vector<int> v4(v3);
    printVector(v4);

}

int main(){
    test1();

    return 0;
}