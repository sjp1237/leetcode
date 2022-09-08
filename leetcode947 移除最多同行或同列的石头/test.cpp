#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


//947. 移除最多的同行或同列石头

//n 块石头放置在二维平面中的一些整数坐标点上。每个坐标点上最多只能有一块石头。
//如果一块石头的 同行或者同列 上有其他石头存在，那么就可以移除这块石头。
//给你一个长度为 n 的数组 stones ，其中 stones[i] = [xi, yi] 表示第 i 块石头的位置，返回 可以移除的石子 的最大数量。


//思路：并查集，消除最多石头的数量=石头总量-石子的集合（行相同或者列相同）
//利用并查集计算总共有多少个集合

class Solution {
public:
    static int removeStones(vector<vector<int>>& stones) {
        vector<int> v(stones.size(), -1);//树的根节点

        for (int i = 0; i < stones.size(); i++) {
            for (int j = i + 1; j < stones.size(); j++) {
                vector<int>& vx = stones[i];
                vector<int>& vy = stones[j];

                //只有当同行或者同列的时候才进行合并
                if (vx[0] == vy[0] || vx[1] == vy[1]) {
                    int rootx = i, rooty = j;
                    while (v[rootx] >= 0) {//找到相同的根节点
                        rootx = v[rootx];
                    }

                    while (v[rooty] >= 0) {
                        rooty = v[rooty];
                    }

                    if (rootx != rooty) {
                        v[rootx] += v[rooty];
                        v[rooty] = rootx;
                    }
                }
            }
        }
        int res = 0;
        for (auto i : v) {
            if (i < 0) {
                res++;
            }
        }
        return stones.size() - res;
    }
};


int main() {
    vector<vector<int>> vv = { {0,0} ,{0,1},{1,0},{1,2},{2,1},{2,2} };
    cout << Solution::removeStones(vv)<<endl;

    return 0;
}