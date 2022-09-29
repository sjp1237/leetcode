#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。
//
//输入：s1 = "waterbottle", s2 = "erbottlewat"
//输出：True


class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        //如果两个字符串大小不同，则s2一定不是由s1旋转而成
        if (s1.size() != s2.size())return false;
        int n = s1.size();
        if (n == 0)return true;
        //从每一个字符串开始，让s1与s2一个一个比较
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