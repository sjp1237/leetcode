#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
//要求不能创建任何新的节点，只能调整树中节点指针的指向。

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
    Node* head = nullptr;//链表的头节点
    Node* treeToDoublyList(Node* root) {
        if (!root)return nullptr;
        _treeToDoublyList(root);
        //中序遍历后，pre是最后一个节点
        pre->right = head;
        head->left = pre;
        return head;
    }

    //中序遍历
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