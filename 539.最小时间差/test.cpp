#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


//539.最小时间差	
//给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。
//思路：
//因为总共的分钟数有60*24=1440，如果timePoints的数量大于1440，那么一定有有时间重合，因此最小时间差为0



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
        sort(timePoints.begin(), timePoints.end());//时间从小到大进行排序
        int preminute = GetMinute(timePoints[0]);
        for (int i = 1; i < timePoints.size(); i++) {
            //计算相邻每两个相邻的时间差
            int curminute = GetMinute(timePoints[i]);
            Min_minute = min(Min_minute, curminute - preminute);
            preminute = curminute;
        }
        //计算第一个时间和最后一个的时间差
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

