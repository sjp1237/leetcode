#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//����һ�ö��������������ö���������ת����һ�������ѭ��˫������
//Ҫ���ܴ����κ��µĽڵ㣬ֻ�ܵ������нڵ�ָ���ָ��

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node() {}
    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* pre = nullptr;//
    Node* head = nullptr;//�����ͷ�ڵ�
    Node* treeToDoublyList(Node* root) {
        if (!root)return nullptr;
        _treeToDoublyList(root);
        //���������pre�����һ���ڵ�
        pre->right = head;
        head->left = pre;
        return head;
    }

    //�������
    void _treeToDoublyList(Node* root) {
        if (!root)return;
        _treeToDoublyList(root->left);
        if (head == nullptr) {
            head = root;
            pre = root;
        }
        else {
            pre->right = root;
            root->left = pre;
            pre = root;
        }
        _treeToDoublyList(root->right);
    }
};