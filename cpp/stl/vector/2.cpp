// -------- vector 赋值操作 --------
/*
功能描述：
- 给vector容器进行赋值
函数原型：
- vector& operator=(const vector& vec);       // 重载等号运算符
- assign(beg, end);                           // 将[beg, end]区间中的数据拷贝赋值给本身 
- assign(n, elem);                            // 将n个elem拷贝赋值给本身
*/

#include <iostream>
#include <vector>

void printVector(std::vector<int>& v){
    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test1(){
    std::vector<int> v1;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    printVector(v1);

    // 赋值 
    // operator = 
    std::vector<int> v2;
    v2= v1;
    printVector(v2);

    // assign
    std::vector<int> v3;
    v3.assign(v1.begin(), v1.end()); // 区间左闭右开
    printVector(v3);

    // n个elem 赋值
    std::vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);

}

int main(){
    test1();

    return 0;
}