#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//�ַ�����ת�����������ַ���s1��s2�����д������s2�Ƿ�Ϊs1��ת���ɣ����磬waterbottle��erbottlewat��ת����ַ�������
//
//���룺s1 = "waterbottle", s2 = "erbottlewat"
//�����True


class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        //��������ַ�����С��ͬ����s2һ��������s1��ת����
        if (s1.size() != s2.size())return false;
        int n = s1.size();
        if (n == 0)return true;
        //��ÿһ���ַ�����ʼ����s1��s2һ��һ���Ƚ�
        for (int i = 0; i < s1.size(); i++) {
            bool flag = true;
            for (int j = 0; j < s2.size(); j++) {
                if (s1[(i + j) % (n)] != s2[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag)return true;
        }
        return false;
    }
};