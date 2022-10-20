#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//打印99乘法表
void test1() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= i; j++) {
			cout << i << "*" << j << "=" << i * j << " ";
		}
		cout << endl;
	}
}


//链表的反转
struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (!pHead)return pHead;
		ListNode* pre = nullptr;
		ListNode* cur = pHead;
		while (cur) {
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};
//链表中环的入口结点
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead) {
		ListNode* slow = pHead, * fast = pHead;

		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				break;
			}
		}
		if (!fast->next || !fast)return nullptr;

		slow = pHead;
		while (true) {
			if (slow == fast)break;
			slow = slow->next;
			fast = fast->next;

		}
		return fast;
	}
};


//链表中倒数最后k个结点
class Solution {
public:
ListNode* FindKthToTail(ListNode* pHead, int k) {
	// write code here
	if (!pHead)return nullptr;
	ListNode* head = pHead, * tail = pHead;
	while (--k && tail) {
		tail = tail->next;
	}
	if (!tail)return tail;

	while (tail->next) {
		head = head->next;
		tail = tail->next;
	}
	return head;
}
};



int main() {
	test1();
}


