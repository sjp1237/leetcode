#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
#include<unordered_map>
//题目：
//有 n 个人被分成数量未知的组。每个人都被标记为一个从 0 到 n - 1 的唯一ID 。
//给定一个整数数组 groupSizes ，其中 groupSizes[i] 是第 i 个人所在的组的大小。例如，如果 groupSizes[1] = 3 ，则第 1 个人必须位于大小为 3 的组中。
//返回一个组列表，使每个人 i 都在一个大小为 groupSizes[i] 的组中。
//每个人应该 恰好只 出现在 一个组 中，并且每个人必须在一个组中。如果有多个答案，返回其中 任何 一个。可以 保证 给定输入 至少有一个 有效的解。

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        //将组的大小与人的id进行映射进哈希表中
        for (int i = 0; i < groupSizes.size(); i++) {
            int tmp = groupSizes[i]; 
                mp[tmp].push_back(i);
        }

        vector<vector<int>> res;
        for (auto v : mp) {
            int count = v.first;//组的大小
            vector<int> a;
            //v.second是相对应组的id
            for (auto i : v.second) {
                a.push_back(i);
                if (a.size() == count) {
                    res.push_back(a);
                    a.clear();
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> tmp = { 2,1,3,3,3,2 };
    vector<vector<int>> res=s.groupThePeople(tmp);
    for (auto v : res) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}