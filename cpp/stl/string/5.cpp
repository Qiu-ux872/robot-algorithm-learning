// --------- string 字符串比较 --------
/*
功能描述：
- 字符串之间的比较
比较方式：
- 字符串比较是按字符的ASCII码进行比较
- = 返回 0
- > 返回 1
- < 返回 -1
函数原型：
- int compare(const string& s) const;    // 与字符串s比较
- int compare(const char* s) const;      // 与字符串s比较
*/

#include <iostream>
#include <string>

void test01(){
    // 通常按照ASCII码比较
    // 常用于判断是否相等
    std::string str1 = "xello";
    std::string str2 = "hello";

    if(str1.compare(str2) == 0){
        std::cout << "str1 == str2" << std::endl;
    } else if(str1.compare(str2) > 0){
        std::cout << "str1 > str2" << std::endl;
    } else if(str1.compare(str2) < 0){
        std::cout << "str1 < str2" << std::endl;
    }
}

int main(){
    test01();

    return 0;
}