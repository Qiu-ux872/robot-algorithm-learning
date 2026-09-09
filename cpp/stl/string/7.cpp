// -------- string 的插入和删除 --------
/*
功能描述：
- 对string字符串进行插入和删除字符操作
函数原型：
- string& insert(int pos, char* s);             // 插入字符串
- string& insert(int pos, const string& str);   // 插入字符串
- string& insert(int pos, int n, char c);       // 在指定位置插入n个字符c
- string& erase(int pos, int n = npos);         // 删除从pos开始的n个字符
*/

#include <iostream>
#include <string>

void test01(){
    // 插入
    std::string str = "hello";
    str.insert(1, "111");
    std::cout << "str = " << str << std::endl;

    // 删除
    str.erase(1, 3); // 起始位置，删除个数
    std::cout << "str = " << str << std::endl;

}

int main(){
    test01();

    return 0;
}