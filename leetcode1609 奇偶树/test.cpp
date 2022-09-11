#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<queue>


//如果一棵二叉树满足下述几个条件，则可以称为 奇偶树 ：
//二叉树根节点所在层下标为 0 ，根的子节点所在层下标为 1 ，根的孙节点所在层下标为 2 ，依此类推。
//偶数下标 层上的所有节点的值都是 奇 整数，从左到右按顺序 严格递增
//奇数下标 层上的所有节点的值都是 偶 整数，从左到右按顺序 严格递减
//给你二叉树的根节点，如果二叉树为 奇偶树 ，则返回 true ，否则返回 false


//思路：二叉树层序遍历，
//如果是偶数层，则判断节点是否为奇数，且判断是否单调递减
//如果是奇数层，判断节点是否为偶数，且是否单调递增
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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 0;//第level层
        q.push(root);
        while (!q.empty()) {
            int size = q.size();//每一层的节点个数
            int prevalue = level % 2 == 0 ? INT_MIN : INT_MAX;
            //每一层的遍历
            for (int i = 0; i < size; i++) {
                
                TreeNode* cur = q.front();
                q.pop();
                if (level % 2 == 0) {
                    //奇数层
                    if (cur->val % 2 == 0)return false;
                    if (cur->val <= prevalue)return false;
                }
                else {
                    //偶数层
                    if (cur->val % 2)return false;
                    if (cur->val >= prevalue)return false;
                }
                prevalue = cur->val;

                if (cur->left)q.push(cur->left);
                if (cur->right)q.push(cur->right);
            }
            level++;//层数+1
        }
        return true;
    }
};

