#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//
//请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，
//还有一个 random 指针指向链表中的任意节点或者 null。

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)return NULL;
        Node* cur = head;
        //将复制新节点的新节点链接在每个节点的后边
        while (cur) {
            Node* newnode = new Node(cur->val);
            Node* next = cur->next;
            cur->next = newnode;
            newnode->next = next;
            cur = next;
        }

       
        Node* nhead = head->next;
        cur = head;
        //设置新节点的random
        while (cur) {
            Node* ncur = cur->next;
            if (cur->random)
                ncur->random = cur->random->next;
            cur = ncur->next;
        }

        //将新链表和旧链表进行分开
        cur = head;
        while (cur->next) {
            Node* next = cur->next;
            cur->next = next->next;
            cur = next;
        }
        return nhead;
    }
};