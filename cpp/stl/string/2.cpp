// -------- string赋值操作 ---------
/*
- string& operator = (const char* s);        // char*类型字符串 赋值给当前字符串
- string& operator = (const string &s);      // 把字符串s赋给当前的字符串
- string& operator = (char c);               // 字符赋值给当前的字符串
- string& assign(const char *s);             // 把字符串s赋给当前的字符串
- string& assign(const char *s, int n);      // 把字符串的前n个字符赋给当前字符串
- string& assign(const string &s);           // 把字符串s赋给当前字符串
- string& assign(int n, char c);             // 把n个字符c赋给当前字符串
*/
#include <iostream>
#include <algorithm>
#include <string>

void test01(){
    std::string str1;
    str1 = "Hello World!";
    std::cout << "str1 = " << str1 << std::endl;

    std::string str2;
    str2 = str1;
    std::cout << "str2 = " << str2 << std::endl;

    std::string str3;
    str3 = 'a';
    std::cout << "str3 = " << str3 << std::endl;

    std::string str4;
    str4.assign("Hello World!");
    std::cout << "str4 = " << str4 << std::endl;

    std::string str5;
    str5.assign("Hello World", 5);
    std::cout <<  "str5 = " << str5 << std::endl;

    std::string str6;
    str6.assign(str5);
    std::cout << "str6 = " << str6 << std::endl;

    std::string str7;
    str7.assign(10, 'w');
    std::cout << "str7 = " << str7 << std::endl;

}

int
main(){
    test01();

    return 0;
}