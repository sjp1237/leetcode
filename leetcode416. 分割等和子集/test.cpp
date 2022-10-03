#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
//输入：nums = [1, 5, 11, 5]
//输出：true


class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for (auto i : nums)
        {
            sum += i;
        }

        if (sum % 2 == 1)
            return false;

        int dpSize = sum / 2;
        vector<int> dp(dpSize + 1, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = dpSize; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j - nums[i]] + nums[i], dp[j]);
            }
        }

        if (dp[dpSize] == dpSize)
            return true;
        return false;
    }
};
