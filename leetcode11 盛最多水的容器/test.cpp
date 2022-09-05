#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


//题目：盛最多水的容器
//给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是(i, 0) 和(i, height[i]) 。
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//返回容器可以储存的最大水量。
//说明：你不能倾斜容器。

//思路：创建左右指针，左右指针的距离是容器的底
//找到左右边的最小高，容器的体积=容器的底*最小高
//记录容器体积的最大值，再将最小高的边向中间靠拢，重复如上步骤

class Solution {
public:
    static int maxArea(vector<int>& height) {
        long res = 0;//记录容器盛最多的水
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int minheight = min(height[left], height[right]);
            long tmp = (long)(right - left) * minheight;
            res = max(res, tmp);
            if (minheight == height[left])left++;
            else right--;
        }
        return res;
    }
};


int main() {
    vector<int> tmp = { 1, 8, 6, 2, 5, 4, 8, 3, 7,100 };
    int res = Solution::maxArea(tmp);
    cout << res << endl;
    return 0;
}