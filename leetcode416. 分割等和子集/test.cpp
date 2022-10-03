#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//����һ�� ֻ���������� �� �ǿ� ���� nums �������ж��Ƿ���Խ��������ָ�������Ӽ���ʹ�������Ӽ���Ԫ�غ���ȡ�
//���룺nums = [1, 5, 11, 5]
//�����true


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
