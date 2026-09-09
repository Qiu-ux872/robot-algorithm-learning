// -------- vector容器和大小 --------
/*
功能描述：
- 对vector容器的容量和大小操作
函数原型：
- empty();                        // 判断容器是否为空
- capacity();                     // 容器的容量
- size();                         // 返回容器中元素的个数
- resize(int num);                // 重新制定容器的长度为num，若容器变长，则以elem值填充新位置
                                  // 如果容器变短，则末尾超出容器长度的元素被删除
- resize(int num, elem);          // 重新制定容器的长度为num，若容器变长，则以elem值填充新位置
                                  // 如果容器变短，则末尾超出容器长度的元素被删除
*/

#include <vector>
#include <iostream>

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

    if(v1.empty()){
        // 为真 代表容器为空
        std::cout << "v1为空" << std::endl;
    } else {
        std::cout << "v1不为空" << std::endl;
        std::cout << "v1的容量为:" << v1.capacity() << std::endl;
        std::cout << "v1的大小为:" << v1.size() << std::endl;
    }

    // 重新指定大小
    // 自定义默认填充新值
    v1.resize(15, 1);
    printVector(v1);

    // 如果重新指定的比原来短了超出的部分会删除
    v1.resize(5, 1);
    printVector(v1);
}

int main(){
    test1();

    return 0;
} 