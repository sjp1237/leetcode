#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<queue>


//���һ�ö���������������������������Գ�Ϊ ��ż�� ��
//���������ڵ����ڲ��±�Ϊ 0 �������ӽڵ����ڲ��±�Ϊ 1 ��������ڵ����ڲ��±�Ϊ 2 ���������ơ�
//ż���±� ���ϵ����нڵ��ֵ���� �� �����������Ұ�˳�� �ϸ����
//�����±� ���ϵ����нڵ��ֵ���� ż �����������Ұ�˳�� �ϸ�ݼ�
//����������ĸ��ڵ㣬���������Ϊ ��ż�� ���򷵻� true �����򷵻� false


//˼·�����������������
//�����ż���㣬���жϽڵ��Ƿ�Ϊ���������ж��Ƿ񵥵��ݼ�
//����������㣬�жϽڵ��Ƿ�Ϊż�������Ƿ񵥵�����
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
        int level = 0;//��level��
        q.push(root);
        while (!q.empty()) {
            int size = q.size();//ÿһ��Ľڵ����
            int prevalue = level % 2 == 0 ? INT_MIN : INT_MAX;
            //ÿһ��ı���
            for (int i = 0; i < size; i++) {
                
                TreeNode* cur = q.front();
                q.pop();
                if (level % 2 == 0) {
                    //������
                    if (cur->val % 2 == 0)return false;
                    if (cur->val <= prevalue)return false;
                }
                else {
                    //ż����
                    if (cur->val % 2)return false;
                    if (cur->val >= prevalue)return false;
                }
                prevalue = cur->val;

                if (cur->left)q.push(cur->left);
                if (cur->right)q.push(cur->right);
            }
            level++;//����+1
        }
        return true;
    }
};

