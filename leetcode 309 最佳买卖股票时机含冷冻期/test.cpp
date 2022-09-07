﻿#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>
using namespace std;

//题目；309. 最佳买卖股票时机含冷冻期

//给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
//设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票） :
//卖出股票后，你无法在第二天买入股票(即冷冻期为 1 天)。
//注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）

//没有冷冻期=上一天冷冻期结束，或者上一天冷冻期的非冷冻期
//有冷冻期=当天股票卖出去
//持有股票=买入当天股票，或者上一天持有股票
class Solution {
public:
    static int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
        //0 不持有股票，没有冷冻期
        //1 不持有股票，有冷冻期
        //2 持有股票
        int size = prices.size() - 1;
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] -= prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
            dp[i][1] = dp[i - 1][2] + prices[i];
            dp[i][2] = max(dp[i - 1][0] - prices[i], dp[i - 1][2]);
        }
        return max(dp[size][0], dp[size][1]);
    }
};


int main() {
    vector<int> v = { 1,2,3,0,2 };
    int res = Solution::maxProfit(v);
    cout << res << endl;
}