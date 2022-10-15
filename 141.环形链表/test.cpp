#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
//141. ��������
//����һ�������ͷ�ڵ� head ���ж��������Ƿ��л���
//�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ���
//Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����
//ע�⣺pos ����Ϊ�������д��� ��������Ϊ�˱�ʶ�����ʵ�������
//��������д��ڻ� ���򷵻� true �� ���򣬷��� false ��
 struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};


 //����ָ��
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head) return false;
        ListNode* fast = head, * slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) return true;
        }
        return false;
    }
};
