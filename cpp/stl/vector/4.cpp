// -------- vector 插入和删除 --------
/*
功能描述：
- 对vector容器进行插入、删除操作
函数原型：
- push_back(ele);                                   // 尾部插入元素ele
- pop_back();                                       // 删除最后一个元素
- insert(const_iterator pos, ele);                  // 迭代器指向位置pos插入元素ele
- insert(const_iterator pos, int count, ele);       // 迭代器指向位置pos插入count个元素ele
- erase(const_iterator pos);                        // 删除迭代器指向的元素
- erase(const_iterator start, const_iterator end);  // 删除迭代器从start到end之间的元素
- clear();                                          // 删除容器中的所有元素
*/

#include <iostream>
#include <vector>

void printVector(std::vector<int>& v){
    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


void test01(){
    std::vector<int> v1;
    // 尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    // 遍历
    printVector(v1);

    // 尾删
    v1.pop_back();

    printVector(v1);

    // 插入 参数：迭代器 所插数值
    v1.insert(v1.begin(), 100);
    printVector(v1);

    // 参数：  迭代器  所插数值个数 所插数值
    v1.insert(v1.begin(), 2, 1000);
    printVector(v1);

    // 删除
    v1.erase(v1.begin());
    printVector(v1);

    // 提供整个vector区间即整个清空
    v1.erase(v1.begin(), v1.end());
    printVector(v1);

    v1.clear();
    printVector(v1);

}

int main(){
    test01();

    return 0;
}