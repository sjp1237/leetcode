#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


//����������ĸ��ڵ� root ��һ������Ŀ��� targetSum ���ҳ����� �Ӹ��ڵ㵽Ҷ�ӽڵ� ·���ܺ͵��ڸ���Ŀ��͵�·����
//Ҷ�ӽڵ� ��ָû���ӽڵ�Ľڵ㡣
// ˼·��
//���ݣ��������������е�·��������ӣ�������Ҷ�ӽڵ㣬�ж��Ƿ���ӽ����target���

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
         //����Ҷ�ӽڵ�
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


