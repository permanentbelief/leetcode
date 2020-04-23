#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


class ListNode
{

public:
	int val;
	ListNode* next;
	ListNode(int val_)
		:val(val_)
		, next(nullptr)
	{
		
	}
};

class Solution {
public:
	ListNode* reverse(ListNode* head)
	{
		ListNode* prev = nullptr;
		ListNode* cur = head;
		while (cur != nullptr)
		{
			ListNode* next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}
	
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ll1 = reverse(l1);
		ListNode* ll2 = reverse(l2);

		ListNode* lr = nullptr;
		ListNode* lrtmp = lr;
		int temp = 0;
		while (ll1 != nullptr || ll2 != nullptr)
		{
			int a = ll1 == nullptr ? 0 : ll1->val;
			int b = ll2 == nullptr ? 0 : ll2->val;
			if (ll1 != nullptr)
				ll1 = ll1->next;
			if (ll2 != nullptr)
				ll2 = ll2->next;
			int next = a + b + temp;
			temp = next / 10;

			ListNode* cur = new ListNode(next % 10);

			if (lrtmp == nullptr)
			{
				lr = cur;
				lrtmp = lr;
			}
			else
			{
				lrtmp->next = cur;
				lrtmp = lrtmp->next;
			}
		}
		if (temp == 1)
			lrtmp->next = new ListNode(1);


		ListNode* llr = reverse(lr);
		return llr;
	}
};
//
//int main()
//{
//	Solution s;
//	ListNode* head1 = new ListNode(7);
//	head1->next = new ListNode(2);
//	head1->next->next = new ListNode(4);
//	head1->next->next->next = new ListNode(3);
//
//	ListNode* head2 = new ListNode(5);
//	head2->next = new ListNode(6);
//	head2->next->next = new ListNode(4);
//
//	ListNode* cur = s.addTwoNumbers(head1, head2);
//	while (cur)
//	{
//		cout << cur->val << " ";
//		cur = cur->next;
//	}
//	cout << endl;
//
//	system("pause");
//}