#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace;

//leetcode 707. �������
//��������ʵ�֡�������ѡ��ʹ�õ������˫�����������еĽڵ�Ӧ�þ����������ԣ�val �� next��val �ǵ�ǰ�ڵ��ֵ��next ��ָ����һ���ڵ��ָ�� / ���á����Ҫʹ��˫����������Ҫһ������ prev ��ָʾ�����е���һ���ڵ㡣���������е����нڵ㶼�� 0 - index �ġ�
//����������ʵ����Щ���ܣ�
//get(index)����ȡ�����е� index ���ڵ��ֵ�����������Ч���򷵻� - 1��
//addAtHead(val)��������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪ val �Ľڵ㡣������½ڵ㽫��Ϊ����ĵ�һ���ڵ㡣
//addAtTail(val)����ֵΪ val �Ľڵ�׷�ӵ���������һ��Ԫ�ء�
//addAtIndex(index, val)���������еĵ� index ���ڵ�֮ǰ���ֵΪ val  �Ľڵ㡣��� index ��������ĳ��ȣ���ýڵ㽫���ӵ������ĩβ����� index ���������ȣ��򲻻����ڵ㡣���indexС��0������ͷ������ڵ㡣
//deleteAtIndex(index)��������� index ��Ч����ɾ�������еĵ� index ���ڵ㡣


struct node {
    node(int _val = 10) :val(_val) {}
    node* next = nullptr;
    node* pre = nullptr;
    int val;

};
class MyLinkedList {
public:
    int size = 0;//��¼����Ľڵ����
    node* head;//
    node* tail;
    MyLinkedList() {
        head = new node(0);
        tail = new node(0);
        head->next = tail;
        tail->pre = head;
    }

    //��ȡ�����е� index ���ڵ��ֵ
    int get(int index) {
        if (index < 0 || index >= size)return -1;
        node* cur = head->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    //������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪ val �Ľڵ㡣
    void addAtHead(int val) {
        node* cur = new node(val);
        node* next = head->next;
        head->next = cur;
        cur->pre = head;

        cur->next = next;
        next->pre = cur;
        size++;
    }

    //��ֵΪ val �Ľڵ�׷�ӵ���������һ��Ԫ�ء�
    void addAtTail(int val) {
        node* cur = new node(val);
        node* pre = tail->pre;
        pre->next = cur;
        cur->pre = pre;

        tail->pre = cur;
        cur->next = tail;
        size++;
    }

    //�������еĵ� index ���ڵ�֮ǰ���ֵΪ val  �Ľڵ�
    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);//
        }
        else if (index == size) {
            addAtTail(val);
        }
        else if (index > size) {
            return;
        }
        else {
            node* cur = head->next;
            while (index--) {
                cur = cur->next;
            }
            node* newnode = new node(val);
            node* pre = cur->pre;
            pre->next = newnode;
            newnode->pre = pre;

            newnode->next = cur;
            cur->pre = newnode;
            size++;
        }
    }

    //������� index ��Ч����ɾ�������еĵ� index ���ڵ㡣
    void deleteAtIndex(int index) {
        if (index >= 0 && index < size) {
            node* cur = head->next;
            while (index--) {
                cur = cur->next;
            }

            //
            node* pre = cur->pre;
            node* next = cur->next;
            pre->next = next;
            next->pre = pre;
            delete cur;
            cur = nullptr;
            size--;
        }
    }
};
