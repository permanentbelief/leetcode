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
��Ѷ �澭 �е� һ��

��һ������,a[i] Ϊ��ǰ�˵����, �������ҿ������ߵ��� �� ��һ����������(�ݼ����п�����), ��ÿ���˶�����󿴵��������Ǽ���?

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
//	//��� 
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
unique_ptr���� ���������ָ������Ȩ�� ����ָ��
unoque_ptr���� ��װһ��ԭʼ��ָ�룬�������������ڡ�����������ʱ����������������ɾ��������ԭʼָ��
unique_ptr ����->��* ��������� ��˿�������ָͨ��һ��ʹ��

�޷����� unique_ptr����,ֻ���ƶ���ÿһ��unique_ptr����ԭʼָ���Ψһ������

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