// -------- list插入和删除 --------
/*
函数原型：
- push_back(elem);
- pop_back();
- push_front(elem);
- pop_front();
- insert(pos, elem);        // pos --> iterator
- insert(pos, n, elem);
- insert(pos, beg, end);
- clear();
- erase(beg, end);
- erase(pos);
- remove(elem);     // 删除所有elem
*/
#include <iostream>
#include <list>

void printList(const std::list<int> l){
    for(std::list<int>::const_iterator it = l.begin(); it != l.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test(){
    std::list<int> l;

    // 尾插
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    // 头插
    l.push_front(100);
    l.push_front(200);
    l.push_front(300);

    printList(l); // 300 200 100 10 20 30

    // 尾删
    l.pop_back();
    printList(l); // 300 200 100 10 20

    // 头删
    l.pop_front();
    printList(l);

    // insert插入
    l.insert(l.begin(), 1000);
    printList(l); // 1000 300 200 100 10 20
    std::list<int>::iterator it = l.begin();
    it++;
    l.insert(it, 10000);
    printList(l);

    // 删除
    it = l.begin();
    l.erase(++it);
    printList(l);

    // remove
    l.remove(20);
    printList(l);

    l.clear();
    printList(l);

}

int main(){
    test();

    return 0;
}