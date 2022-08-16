#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


//539.��Сʱ���	
//����һ�� 24 Сʱ�ƣ�Сʱ:���� "HH:MM"����ʱ���б��ҳ��б�����������ʱ�����Сʱ���Է�������ʾ��
//˼·��
//��Ϊ�ܹ��ķ�������60*24=1440�����timePoints����������1440����ôһ������ʱ���غϣ������Сʱ���Ϊ0



class Solution {
public:
    static int GetMinute(string s) {
        int h = stoi(s.substr(0, 2));
        int m = stoi(s.substr(3, 2));
        return h * 60 + m;
    }
    static int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() >= 1440)//
            return 0;
        int Min_minute = INT_MAX;
        sort(timePoints.begin(), timePoints.end());//ʱ���С�����������
        int preminute = GetMinute(timePoints[0]);
        for (int i = 1; i < timePoints.size(); i++) {
            //��������ÿ�������ڵ�ʱ���
            int curminute = GetMinute(timePoints[i]);
            Min_minute = min(Min_minute, curminute - preminute);
            preminute = curminute;
        }
        //�����һ��ʱ������һ����ʱ���
        int firstminute = GetMinute(timePoints[0]);
        int endminute = 1440 - GetMinute(timePoints[timePoints.size() - 1]);
        Min_minute = min(Min_minute, endminute + firstminute);
        return Min_minute;
    }
};


int main() {
    vector<string> s1{ {"23:59"},{"00 : 00"} };
    int res1 = Solution::findMinDifference(s1);
    cout << res1 << endl;

    //vector<string> s2{ "23:59","01 : 00" };
    //int res2 = Solution::findMinDifference(s2);
    //cout << res2 << endl;
}

