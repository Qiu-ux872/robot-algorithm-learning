// -------- string子串 --------
/*
功能描述：
- 从字符串中获取想要的子串
函数原型：
- string substr(int pos = 0, int n = npos) const;  // 返回由pos开始的n个字符组成的字符串
*/

#include <iostream>
#include <string>

// string求子串
void test01(){
    std::string str = "abcdef";
    std::string subStr = str.substr(1, 3);
    std::cout << "subStr = " << subStr << std::endl;
}

// 实用操作
void test02(){
    std::string email = "xiaoqiu@qq.com";
    
    // 从邮箱地址获取用户名信息
    int pos = email.find("@");
    std::string usrName = email.substr(0, pos); // pos是截取的个数 不用-1
    std::cout << "usrName = " << usrName << std::endl;
}

int main(){
    test02();

    return 0;
}