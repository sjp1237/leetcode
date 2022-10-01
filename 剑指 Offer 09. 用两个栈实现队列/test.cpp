#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
using namespace std;
//用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
//分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 - 1)



class CQueue {
private:
    stack<int> s1;//s1 将数据push
    stack<int> s2;//s2 删除数据
public:
    CQueue() {
    }

    void appendTail(int value) {
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(value);
    }

    int deleteHead() {
        if (s1.empty() && s2.empty())
            return -1;
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int value = s2.top();
        s2.pop();
        return value;
    }
};