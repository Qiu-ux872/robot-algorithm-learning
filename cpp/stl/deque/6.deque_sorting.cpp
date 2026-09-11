// -------- deque 排序 --------
/*
功能描述：
- 利用算法实现对deque容器进行排序
算法：
- sort(iterator beg, iterator end);  // 对beg和end区间内元素排序
*/

#include <iostream>
#include <deque>
#include <algorithm> // 所有标准库提供的算法要包含 algorithm

void printDeque(const std::deque<int> d){
    for(std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test(){
    std::deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    // 300 200 100 10 20 30
    printDeque(d);

    // 排序
    // sort 默认升序 从小到大
    // 对于支持随机访问的迭代器的容器 都可以直接利用sort进行排序
    std::sort(d.begin(), d.end());
    std::cout << "排序后:" << std::endl;
    printDeque(d);

}

int main(){
    test();

    return 0;
}