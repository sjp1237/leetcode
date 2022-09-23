#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace;

//leetcode 707. 设计链表
//设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针 / 引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0 - index 的。
//在链表类中实现这些功能：
//get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回 - 1。
//addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
//addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
//addAtIndex(index, val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
//deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。


struct node {
    node(int _val = 10) :val(_val) {}
    node* next = nullptr;
    node* pre = nullptr;
    int val;

};
class MyLinkedList {
public:
    int size = 0;//记录链表的节点个数
    node* head;//
    node* tail;
    MyLinkedList() {
        head = new node(0);
        tail = new node(0);
        head->next = tail;
        tail->pre = head;
    }

    //获取链表中第 index 个节点的值
    int get(int index) {
        if (index < 0 || index >= size)return -1;
        node* cur = head->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    //在链表的第一个元素之前添加一个值为 val 的节点。
    void addAtHead(int val) {
        node* cur = new node(val);
        node* next = head->next;
        head->next = cur;
        cur->pre = head;

        cur->next = next;
        next->pre = cur;
        size++;
    }

    //将值为 val 的节点追加到链表的最后一个元素。
    void addAtTail(int val) {
        node* cur = new node(val);
        node* pre = tail->pre;
        pre->next = cur;
        cur->pre = pre;

        tail->pre = cur;
        cur->next = tail;
        size++;
    }

    //在链表中的第 index 个节点之前添加值为 val  的节点
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

    //如果索引 index 有效，则删除链表中的第 index 个节点。
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
