#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
using namespace std;
//������ջʵ��һ�����С����е��������£���ʵ�������������� appendTail �� deleteHead ��
//�ֱ�����ڶ���β�������������ڶ���ͷ��ɾ�������Ĺ��ܡ�(��������û��Ԫ�أ�deleteHead �������� - 1)



class CQueue {
private:
    stack<int> s1;//s1 ������push
    stack<int> s2;//s2 ɾ������
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