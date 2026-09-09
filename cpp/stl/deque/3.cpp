// -------- deque大小操作 --------
/*
功能描述：
- 对deque容器的大小进行操作
函数原型：
- deque.empty();                    // 判断容器是否为空
- deque.size();                     // 返回容器中元素的个数
- deque.resize(num);                // 重新指定容器额的长度为num 若容器变长则以默认值填充新位置
                                    // 如果容器变短 则末尾超出容器长度的元素被删除
- deque.resize(num, elem);          // 重新指定容器额的长度为num 若容器变长则以elem填充新位置
                                    // 如果容器变短 则末尾超出容器长度的元素被删除
------------ !ps:deque中没有容量概念 ------------
*/

#include <iostream>
#include <deque>

void printDeque(const std::deque<int>& d){
    for(std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test(){
    std::deque<int> d1;
    for(int i = 0; i < 10; i++){
        d1.push_back(i);
    }
    printDeque(d1);

    if(d1.empty()){
        std::cout << "d1为空" << std::endl;
    } else {
        std::cout << "d1不为空" << std::endl;
        std::cout << "d1的大小:" << d1.size() << std::endl;
    }

    // 重新指定大小
    // 可用重载版本自定义填充数
    d1.resize(15, 1);
    printDeque(d1);
    
    d1.resize(5);
    printDeque(d1);

}

int
main(){
    test();

    return 0;
}