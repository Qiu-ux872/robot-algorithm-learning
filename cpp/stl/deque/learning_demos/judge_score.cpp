#include <cstddef>
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <ctime>
/*
1、创建五名选手 放到vector中
2、遍历vector 取出每一个选手进行for循环 把10个评分存到deque
3、sort算法对deque容器中分数排序 去除最高和最低分
4、deque遍历累加总分
5、取平均分
*/

class Player{
public:
    Player(std::string name, int score){
        this->m_Name = name;
        this->m_Score = score;
    }

    std::string m_Name;
    int m_Score;

};

void create_player(std::vector<Player>& v){
    {
        std::string nameSeed = "ABCDE";
        for(int i = 0; i < 5; i++){
            std::string name = "player";
            name += nameSeed[i];

            int score = 0;

            Player p(name, score);
            // 将创建的Player对象放入v
            v.push_back(p);
        }
    }
}

// 打分
void setScore(std::vector<Player>& v){
    for(std::vector<Player>::iterator it = v.begin(); it != v.end(); it++){
        std::deque<int> d;
        // 将评委打分放入deque容器中
        for(int i = 0; i < 10; i++){
            int score = rand() % 41 + 60;  // 区间为 60 ~ 100
            d.push_back(score);
        }

        std::cout << "选手: " << it->m_Name << " 分数: ";
        for(std::deque<int>::iterator dit = d.begin(); dit != d.end(); dit++){
            std::cout << *dit << " ";
        }
        std::cout << std::endl;

        // 排序
        std::sort(d.begin(), d.end());

        // 去除最高和最低分
        d.pop_back();
        d.pop_front();

        int sum = 0;
        // 取平均分
        for(std::deque<int>::iterator dit = d.begin(); dit != d.end(); dit++){
            sum += *dit; // 累加
        }
        int avg = sum / d.size();

        // 将平均分赋值给选手
        it->m_Score = avg;
        std::cout << "选手: " << it->m_Name << " 最终平均分: " << it->m_Score << std::endl;
    }
}

int main(){
    // 随机数种子
    std::srand((unsigned int)time(NULL));

    // 创建5名选手
    std::vector<Player> v;
    create_player(v);

    setScore(v);   

    return 0;
}