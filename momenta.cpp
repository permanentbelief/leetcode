#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

#include <memory>

using namespace std;



/*
腾讯 面经 中的 一题

给一段序列,a[i] 为当前人的身高, 能向左看右看比他高的人 和 第一个比他矮的(递减序列看不到), 问每个人都能最大看到的人数是几个?

*/

//
//int cnt[10] = { 0 };
//int cnt1[10] = { 0 };
//int a[10] = { 9, 3, 1, 4, 5, 7, 2, 9, 4, 2 };
////1 6 6 5 4 4 3 2 2 2 
//void f()
//{
//	stack<int> s;
//	for (int i = 0; i < 10; i++)
//	{
//		while (s.size() && a[s.top()] <= a[i])
//		{
//			int t = s.top();
//			s.pop();
//			cnt[t] = s.size();
//			if (t && a[t - 1] < a[t])
//			{
//				cnt[t] += 1;
//			}
//		}
//		s.push(i);
//	}
//	while (s.size())
//	{
//		int t = s.top();
//		s.pop();
//		cnt[t] = s.size();
//		if (t && a[t - 1] < a[t])
//		{
//			cnt[t] += 1;
//		}
//
//	}
//	//结果 
//
//
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << cnt[i] << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//
//
//	f();
//	reverse(a, a + 10);
//
//	memcpy(cnt1, cnt, sizeof cnt);
//
//	//reverse(cnt, cnt + 10);
//
//	f();
//	reverse(cnt, cnt + 10);
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << cnt1[i] + cnt[i] << " ";
//	}
//	cout << endl;
//}



//const double const *
//double const * const 


//struct Element
//{
//	double value;
//	std::unique_ptr<int> i;
//};
//int main()
//{
//
//}

/*
unique_ptr独享 被管理对象指针所有权的 智能指针
unoque_ptr对象 包装一个原始的指针，并负责生命周期。当对象被销毁时，会在析构函数中删除关联的原始指针
unique_ptr 具有->和* 运算符重载 因此可以像普通指针一样使用

无法复制 unique_ptr对象,只能移动，每一个unique_ptr都是原始指针的唯一所有者

*/
struct Task
{
	int mid;
	Task(int id)
		:mid(id)
	{
		cout << "Constructor" << endl;
	}
	~Task()
	{
		cout << "Destructor" << endl;
	}
};


void testm()
{
	unique_ptr<Task> taskPtr(new Task(23));
	cout << taskPtr.get() << endl;
	int id = taskPtr->mid;
	cout << id << endl;

}
int main()
{

	// testm();
	//unique_ptr<int> ptr1;
	//if (!ptr1)
	//{
	//	cout << "ptr1 is empty" << endl;
	//}
	//else
	//{
	//	cout << "isn't empty" << endl;
	//}
	//unique_ptr<Task> ptr2(new Task(22));
	//ptr2.reset();
	//if (!ptr2)
	//{
	//	cout << "ptr2 is empty" << endl;
	//}
	//else
	//{
	//	cout << "ptr2 isn't empty" << endl;
	//}

	unique_ptr<Task> ptr2(new Task(22));
	cout << ptr2.get() << endl;

	unique_ptr<Task> ptr3(move(ptr2));

	cout << ptr2.get() << endl;
	cout << ptr3.get() << endl;

	system("pause");
	return 0;
}