#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//
//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//你可以假设除了数字 0 之外，这两个数都不会以 0 开

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1, * tail = head;
        ListNode* pre = nullptr;
        ListNode* cur1 = l1, * cur2 = l2;
        while (cur1 && cur2) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        //如果链表l2长度大于链表1，交换指针，使l1的长度大于l2
        if (cur2) {
            head = l2, tail = l2;
            swap(l1, l2);
        }

        int num = 0;//进位数
        while (l1 && l2) {
            int sum = l1->val + l2->val + num;
            num = sum / 10;
            sum = sum % 10;
            tail->val = sum;
            pre = tail;
            tail = tail->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            int sum = l1->val + num;
            num = sum / 10;
            sum = sum % 10;
            tail->val = sum;
            pre = tail;
            tail = tail->next;
            l1 = l1->next;
        }

        //如果最后进位数不为0，则需要创建一个新的节点
        if (num) {
            ListNode* cur = new ListNode(num);
            pre->next = cur;
        }
        return head;
    }
};