#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//
//�������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
//���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����
//����Լ���������� 0 ֮�⣬���������������� 0 ��

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

        //�������l2���ȴ�������1������ָ�룬ʹl1�ĳ��ȴ���l2
        if (cur2) {
            head = l2, tail = l2;
            swap(l1, l2);
        }

        int num = 0;//��λ��
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

        //�������λ����Ϊ0������Ҫ����һ���µĽڵ�
        if (num) {
            ListNode* cur = new ListNode(num);
            pre->next = cur;
        }
        return head;
    }
};