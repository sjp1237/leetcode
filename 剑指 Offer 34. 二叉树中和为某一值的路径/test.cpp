#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


//给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
//叶子节点 是指没有子节点的节点。
// 思路：
//回溯：将二叉树中所有的路径进行相加，当到达叶子节点，判断是否相加结果域target相等

 struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

 class Solution {
 public:
     vector<vector<int>> res;
     void _pathSum(TreeNode* root, int target, int tmp, vector<int>& tmps) {
         if (root == nullptr)return;
         //到达叶子节点
         if (!root->right && !root->left) {
             tmp += root->val;
             if (tmp == target) {
                 tmps.push_back(root->val);
                 res.push_back(tmps);
                 tmps.pop_back();
             }
             return;
         }

         tmps.push_back(root->val);
         if (root->left)
             _pathSum(root->left, target, tmp + root->val, tmps);
         if (root->right)
             _pathSum(root->right, target, tmp + root->val, tmps);
         tmps.pop_back();
     }
     vector<vector<int>> pathSum(TreeNode* root, int target) {
         vector<int> tmp;
         _pathSum(root, target, 0, tmp);
         return res;
     }
 };


