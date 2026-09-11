// -------- 排序案例 --------
/*
案例描述：将Person自定义数据类型进行排序
排序规则：按照年龄进行升序，如果年龄相同按身高降序
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <list>

class Person{
public:
    Person(std::string name, int age, int height){
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }

    std::string m_Name;
    int m_Age;
    int m_Height;

};

// 指定排序规则
bool comparePersonAge(Person& p1, Person& p2){
    // 按年龄升序
    if(p1.m_Age == p2.m_Age){
        // 年龄相同按照身高降序
        return p1.m_Height > p2.m_Height;
    } else {
        return p1.m_Age < p2.m_Age;
    }
}

void test(){
    std::list<Person> l;

    // 准备数据
    Person p1("刘备", 35, 175);
    Person p2("孙权", 18, 185);
    Person p3("赵云", 48, 165);
    Person p4("张飞", 20, 175);
    Person p5("关羽", 48, 190);
    Person p6("关羽", 48, 170);

    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.push_back(p6);

    for(std::list<Person>::iterator it = l.begin(); it != l.end(); it++){
        std::cout << "姓名: " << (*it).m_Name << " 年龄: " << (*it).m_Age << " 身高: " << (*it).m_Height << std::endl;
    }

    // 排序
    std::cout << "-------------------------" << std::endl;
    std::cout << "排序后: " << std::endl;
    l.sort(comparePersonAge);  // 可定义排序规则的函数传入sort
    for(std::list<Person>::iterator it = l.begin(); it != l.end(); it++){
        std::cout << "姓名: " << (*it).m_Name << " 年龄: " << (*it).m_Age << " 身高: " << (*it).m_Height << std::endl;
    }

}

int main(){
    test();

    return 0;
}