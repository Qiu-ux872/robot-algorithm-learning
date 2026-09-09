// --------- string 字符串查找和替代 ----------
/*
功能描述：
- 查找：查找制定字符串是否存在
- 替换：在指定的位置替换字符串
函数原型：
- int find(const string& str, int pos = 0) const;       // 查找str第一次出现位置，从pos开始查找
- int find(const char* s, int pos = 0) const;           // 查找s第一次出现位置，从pos开始查找
- int find(const char* s, int pos, int n) const;        // 从pos位置查找s的前n个字符第一次位置
- int find(const char c, int pos = 0) const;            // 查找字符c第一次出现位置
- int rfind(const string& str, int pos = npos) const;   // 查找str最后一次位置，从pos开始查找
- int rfind(const char* s, int pos = npos) const;       // 查找s最后一次出现的位置，从pos开始查找
- int rfind(const char* s, int pos, int n) const;       // 从pos开始查找s的前n个字符最后一次位置
- int rfind(const char c, int pos = 0) const;           // 查找字符c最后一次出现的位置
- string& replace(int pos, int n, const string& str);   // 替换从pos开始n个字符为字符串str
- string& replace(int pos, int n, const char* s);       // 替换从pos开始的n个字符为字符串s
*/

#include <iostream>
#include <string>

// 查找
void test01(){
    // find
    std::string str1 = "abcdefgde";
    // int pos = str1.find("de"); // 默认从头开始查找，可传入起始位置
    // int pos = str1.find("df");  -----> 若为找到字符串会传入-1
    std::string str_find = "de";
    int pos = str1.find(str_find);
    if(pos == -1){
        std::cout << "为找到字符串" << str_find << std::endl;
    } else {
        std::cout << "找到字符串 pos = " << pos << std::endl;
    }

    // rfind
    int rpos = str1.rfind(str_find);
    if(pos == -1){
        std::cout << "为找到字符串" << str_find << std::endl;
    } else {
        std::cout << "找到字符串 rpos = " << rpos << std::endl;
    }
    // 直观理解，rfind从右往左查找 find从左往右查找
    // 找到字符串 pos = 3
    // 找到字符串 rpos = 7

}

// 替换
void test02(){
    std::string str1 = "abcdefg";
    std::string str_rpl = "1111";
    str1.replace(1, 3, str_rpl); // 当选择了3个字符，替换的字符有3个以上，会将要替换的字符全部替换到原字符串
    std::cout << "replaces str = " << str1 << std::endl;

}


int main(){
    test01();
    test02();

    return 0;
}