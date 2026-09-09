// -------- string 字符串拼接 --------
/*
- string& operator += (const char* str);            // 重载+=操作符
- string& operator += *const char c);               // 重载+=操作符
- string& operator += (const string& str);          // 重载+=操作符
- string& append(const char *s);                    // 把字符串s连接到当前字符串末尾
- string& append(const char *s, int n);             // 把字符串s的前n个字符连接到当前字符串末尾
- string& append(const string &s);                  // 同operator+=(const string& str)
- string& append(const string &s, int pos, int n);  // 字符串s中从pos开始的n个字符连接到字符串末尾
*/

#include <iostream>
#include <string>

void test01(){
    std::string str1 = "我";
    str1 += "爱学习";
    std::cout << "str1 = " << str1 << std::endl;

    str1 += ':';
    std::cout << "str1 = " << str1 << std::endl;

    std::string str2 = "LOL WZRY";
    str1 += str2;
    std::cout << "str1 = " << str1 << std::endl;

    // ======= apend =======
    std::string str3 = "I";
    str3.append(" love ");
    std::cout << "str3 = " << str3 << std::endl;

    str3.append("games abcde", 6); // 空格算一个字符
    std::cout << "str3 = " << str3 << std::endl;

    str3.append(str2);
    std::cout << "str3 = " << str3 << std::endl;

    str3.append(str2, 4, 4);  // 参数2->截取起始位置；参数3->截取字符个数
    std::cout << "str3 = " << str3 << std::endl;
}

int
main(){
    test01();

    return 0;
}