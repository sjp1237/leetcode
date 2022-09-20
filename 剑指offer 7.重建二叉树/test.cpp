#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//题目
/*输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。

假设输入的前序遍历和中序遍历的结果中都不含重复的数字*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

class Solution {
public:
    //preorder:前序遍历
    //inorder：中序遍历
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int begin1, int end1, int begin2, int end2) {
        
        if (begin1 > end1)return NULL;
        int val = preorder[begin1];//根节点
        //
        TreeNode* root = new TreeNode(val);
        int pos = -1;
        for (int i = begin2; i <= end2; i++) {
            if (inorder[i] == val) {
                pos = i;
            }
        }
        int leftsize = pos - begin2;//左子树的
        root->left = _buildTree(preorder, inorder, begin1 + 1, begin1 + leftsize, begin2, pos - 1);//构建左子树
        root->right = _buildTree(preorder, inorder, begin1 + leftsize + 1, end1, pos + 1, end2);//构建右子树
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return _buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};

