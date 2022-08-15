#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//leetcode 682:�������
//��������һ�������������ư�������ļ�¼Ա���ⳡ���������ɻغ���ɣ���ȥ���غϵĵ÷ֿ��ܻ�Ӱ���Ժ󼸻غϵĵ÷֡�
//
//������ʼʱ����¼�ǿհ׵ġ����õ�һ����¼�������ַ����б� ops������ ops[i] ������Ҫ��¼�ĵ� i �������ops ��ѭ��������
//
//���� x - ��ʾ���غ��»�÷��� x
//"+" - ��ʾ���غ��»�õĵ÷���ǰ���ε÷ֵ��ܺ͡���Ŀ���ݱ�֤��¼�˲���ʱǰ�����Ǵ���������Ч�ķ�����
//"D" - ��ʾ���غ��»�õĵ÷���ǰһ�ε÷ֵ���������Ŀ���ݱ�֤��¼�˲���ʱǰ�����Ǵ���һ����Ч�ķ�����
//"C" - ��ʾǰһ�ε÷���Ч������Ӽ�¼���Ƴ�����Ŀ���ݱ�֤��¼�˲���ʱǰ�����Ǵ���һ����Ч�ķ�����
//���㷵�ؼ�¼�����е÷ֵ��ܺ͡�

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

//���Դ���
int main() {
    vector<string> v1{ "5","2","C","D","+" };
    int score1 = Solution::calPoints(v1);
    cout << score1 << endl;

    vector<string> v2{ "5","-2","4","C","D","9","+","+" };
    int score2 = Solution::calPoints(v2);
    cout << score2 << endl;
}
