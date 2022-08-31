#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>

//leetoce 94： 二叉树的中序遍历
 struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    vector<int> res;
    void _inorderTraversal(TreeNode* root) {
        if (!root)return;
        _inorderTraversal(root->left);
        res.push_back(root->val);
        _inorderTraversal(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        _inorderTraversal(root);
        return res;
    }
};

//leetoce 101:对称二叉树
class Solution2 {
public:
    bool _isSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right)return true;//如果两个都是空节点
        if (!left || !right)return false;//只有一个是空节点

        if (left->val != right->val)return false;//两个节点的值不同
        return _isSymmetric(left->left, right->right)
            && _isSymmetric(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return _isSymmetric(root->left, root->right);
    }
};
