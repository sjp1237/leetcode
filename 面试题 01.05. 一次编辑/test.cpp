#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//
//面试题 01.05.一次编辑
//
//字符串有三种编辑操作 : 插入一个英文字符、删除一个英文字符或者替换一个英文字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。

//如果两个字符串相差两个字符以上，那么是不可能一次编辑。
//如果两个字符串只相差一个字符，那么只能只有一个字符串能有一个字符不同。
//如果两个字符串长度相等，那么对应的位置的字符只有一个不同。
class Solution {
public:
    bool oneEditAway(string first, string second) {
        int n = first.size(), m = second.size();
        if (n - m == 1) {
            return  _oneEditAway(first, second);
        }
        else if (m - n == 1) {
            return _oneEditAway(second, first);
        }
        else if (n == m) {
            //字符串相等时
            int flag = 0;//记录不同字符的个数
            for (int i = 0; i < n; i++) {
                if (first[i] != second[i]) {
                    flag++;
                }
                if (flag > 1)return false;
            }

        }
        else {
            return false;
        }
        return true;
    }

    bool _oneEditAway(string& longstr, string& shortstr) {
        int pos1 = 0, pos2 = 0;
        while (pos1 < longstr.size() && pos2 < shortstr.size()) {
            if (longstr[pos1] == shortstr[pos2]) {
                pos1++;
                pos2++;
            }
            else {
                pos1++;
            }

            if (pos1 - pos2 > 1) {
                return false;
            }
        }
        return true;
    }
};