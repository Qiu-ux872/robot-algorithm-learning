// -------- string 字符存取 --------
/*
- string中单个字符存取方式有两种
- char& operator[](int n);   // 通过[]方式获取字符
- char& at(int n);           // 通过at方式获取字符
// ps：获取后可对字符进行修改
*/

#include <iostream>
#include <string>

void test01(){
    std::string str = "hello";
    // std::cout << "str = " << str << std::endl;
    // 1、通过[]访问单个字符 str.size()可获取字符串长度
    for(int i = 0; i < str.size(); i++){
        std::cout << str[i] << " ";
    }
    std::cout << std::endl;

    // 2、通过at方式访问单个字符
    for(int i = 0; i < str.size(); i++){
        std::cout << str.at(i) << " ";
    }
    std::cout << std::endl;

    // 修改单个字符
    str[0] = 'x';
    std::cout << "str = " << str << std::endl; // xello
    str.at(1) = 'x';
    std::cout << "str = " << str << std::endl; // xxllo
}

int main(){
    test01();

    return 0;
}