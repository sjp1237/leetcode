#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//
//��ʵ�� copyRandomList ����������һ�����������ڸ��������У�ÿ���ڵ������һ�� next ָ��ָ����һ���ڵ㣬
//����һ�� random ָ��ָ�������е�����ڵ���� null��

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
        //�������½ڵ���½ڵ�������ÿ���ڵ�ĺ��
        while (cur) {
            Node* newnode = new Node(cur->val);
            Node* next = cur->next;
            cur->next = newnode;
            newnode->next = next;
            cur = next;
        }

       
        Node* nhead = head->next;
        cur = head;
        //�����½ڵ��random
        while (cur) {
            Node* ncur = cur->next;
            if (cur->random)
                ncur->random = cur->random->next;
            cur = ncur->next;
        }

        //��������;�������зֿ�
        cur = head;
        while (cur->next) {
            Node* next = cur->next;
            cur->next = next->next;
            cur = next;
        }
        return nhead;
    }
};