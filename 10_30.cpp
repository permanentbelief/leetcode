#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


//template <class T, int size = 0>
//class Queue
//{
//public:
//	Queue();
//	
//	bool is_empty() const;
//
//	bool is_full() const;
//
//	void enqueue(const T&);
//	
//	T dequeue();
//
//	void traverse() const;
//
//private:
//	T storage[size];
//	int first;
//	int last;
//};
//
//template <class T, int size>
//T Queue<T, size>::dequeue()
//{
//	if (is_empty())
//		return T();
//	
//}
//int main()
//{
//	//Queue<int, 3> q;
//	//q.enqueue(1);
//	//q.enqueue(2);
//	//q.enqueue(3);
//
//	//q.traverse();
//
//	//q.dequeue();
//	//q.dequeue();
//	//q.dequeue();
//
//	//q.is_empty();
//	//q.traverse();
//
//	//int a = 1;
//	//char ch = *(char*)(&a);
//	//cout << (ch == 2) << endl;
//	system("pause");
//}



class Solution {
public:
	Node* copyRandomList(Node* head) {
		map<Node*, Node*> m;

		Node* cur = head;
		while (cur)
		{
			Node* newnode = new Node(cur->val);
			cur = cur->next;
		}

		cur = head;
		while (cur)
		{
			if (m[cur] != nullptr)
			{
				m[cur]->next = m[cur->next];
				m[cur]->random = m[cur->random];
			}
			cur = cur->next;
		}
		return m[head];
	}
};
