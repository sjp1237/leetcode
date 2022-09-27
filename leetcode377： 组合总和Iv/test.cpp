#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
//题目数据保证答案符合 32 位整数范围。。

//dp[i]代表的是能够从nums找出的总和
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<unsigned long> dp(target + 1, 0);
        dp[0] = 1;
        for (long i = 0; i <= target; i++) {
            for (long j = 0; j < nums.size(); j++) {
                if (nums[j] <= i) {
                    dp[i] += dp[i - nums[j]];
                }
                else {
                    break;
                }
            }
        }
        return dp[target];
    }
};