#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>

//leetoce 94�� ���������������
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

//leetoce 101:�Գƶ�����
class Solution2 {
public:
    bool _isSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right)return true;//����������ǿսڵ�
        if (!left || !right)return false;//ֻ��һ���ǿսڵ�

        if (left->val != right->val)return false;//�����ڵ��ֵ��ͬ
        return _isSymmetric(left->left, right->right)
            && _isSymmetric(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return _isSymmetric(root->left, root->right);
    }
};
