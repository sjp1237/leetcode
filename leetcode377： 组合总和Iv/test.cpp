#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//����һ���� ��ͬ ������ɵ����� nums ����һ��Ŀ������ target ������� nums ���ҳ��������ܺ�Ϊ target ��Ԫ����ϵĸ�����
//��Ŀ���ݱ�֤�𰸷��� 32 λ������Χ����

//dp[i]��������ܹ���nums�ҳ����ܺ�
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