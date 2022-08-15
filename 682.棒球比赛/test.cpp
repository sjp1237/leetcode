#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//leetcode 682:棒球比赛
//你现在是一场采用特殊赛制棒球比赛的记录员。这场比赛由若干回合组成，过去几回合的得分可能会影响以后几回合的得分。
//
//比赛开始时，记录是空白的。你会得到一个记录操作的字符串列表 ops，其中 ops[i] 是你需要记录的第 i 项操作，ops 遵循下述规则：
//
//整数 x - 表示本回合新获得分数 x
//"+" - 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此操作时前面总是存在两个有效的分数。
//"D" - 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此操作时前面总是存在一个有效的分数。
//"C" - 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作时前面总是存在一个有效的分数。
//请你返回记录中所有得分的总和。

class Solution {
public:
    static int calPoints(vector<string>& ops) {
        vector<int> st;
        int res = 0;
        for (auto s : ops) {
            switch (s[0]) {
            case '+':
            {
                int i1 = st[st.size() - 1];
                int i2 = st[st.size() - 2];
                int j = i1 + i2;
                res += j;
                st.push_back(j);
                break;
            }
            case 'D':
            {
                int i3 = st[st.size() - 1];
                int j1 = i3 * 2;
                st.push_back(j1);
                res += j1;
                break;
            }
            case 'C':
            {
                int i4 = st[st.size() - 1];
                res -= i4;
                st.pop_back();
                break;
            }
            default:
            {
                int a = stoi(s);
                res += a;
                st.push_back(a);
                break;
            }
            }
        }
        return res;
    }
};

//测试代码
int main() {
    vector<string> v1{ "5","2","C","D","+" };
    int score1 = Solution::calPoints(v1);
    cout << score1 << endl;

    vector<string> v2{ "5","-2","4","C","D","9","+","+" };
    int score2 = Solution::calPoints(v2);
    cout << score2 << endl;
}
