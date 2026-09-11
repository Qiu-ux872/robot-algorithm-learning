// -------- stack常用接口 --------
/*
功能描述：
- 栈容器常用的对外接口
构造函数：
- stacl<T> stk;                 // stack采用模板类实现，stack对象的默认构造形式
- stack(const stack& stk);      // 拷贝构造函数
赋值操作：
- stack& operator = (const stack &stk);  // 重载等号操作符
数据存取：
- push(elem);
- pop();
- top();    // 返回栈顶元素
大小操作：
- empty();
- size();
*/

#include <iostream>
#include <algorithm>
#include <stack>

void test(){
    // 符合先进后出数据结构
    std::stack<int> stk;

    // 入栈
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);

    std::cout << "出栈前大小: " << stk.size() << std::endl;
    // 栈不为空 查看栈顶并执行出栈
    while (!stk.empty()) {
        // 栈顶元素
        std::cout << "栈顶元素: " <<  stk.top() << std::endl;

        // 出栈
        stk.pop();
    }
    std::cout << "栈大小: " << stk.size() << std::endl;

}

int main(){
    test();

    return 0;
}