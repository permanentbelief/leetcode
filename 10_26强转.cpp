#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//class Solution {
//public:
//	void sortColors(vector<int>& nums) {
//		int l = 0;
//		int r = nums.size() - 1;
//
//		int i = 0;
//		while (i <= r)
//		{
//			if (nums[i] == 0)
//			{
//				swap(nums[l], nums[i]);
//				l++;
//				i -= 1;
//			}
//			else if (nums[i] == 2)
//			{
//				swap(nums[r], nums[i]);
//				r--;
//				i -= 1;
//			}
//			i++;
//		}
//
//	}
//};
//int partSort(int *arr, int l, int r)
//{
//	int pre = l - 1;
//	int key = arr[r];
//	for (int i = l; i < r; i++)
//	{
//		if (arr[i] <= key)
//		{
//			if (++pre != i)
//			{
//				swap(arr[pre], arr[i]);
//			}
//		}
//	}
//	swap(arr[++pre], arr[r]);
//	//for (int i = l; i <= r; i++)
//	//{
//	//	cout << arr[i] << " ";
//	//}
//	return pre;
//}
//
//void QuickSort(int *a, int l, int r)
//{
//	stack<int> s;
//	s.push(l);
//	s.push(r);
//	while (s.size())
//	{
//		int r = s.top();
//		s.pop();
//		int l = s.top();
//		s.pop();
//
//		int index = partSort(a,l,r);
//		if (index - 1 > l)
//		{
//			s.push(l);
//			s.push(index - 1);
//		}
//		if (index + 1 < r)
//		{
//			s.push(index + 1);
//			s.push(r);
//		}
//	}
//}
//int main()
//{
//	vector<int> v;
//
//	v = { 1, 3, 5, 2, 10, 4 };
//	int a[6] = { 1, 3, 5, 2, 10, 4 };
//	 QuickSort(a, 0, 5);
//	 for (int i = 0; i <= 5; i++)
//	 {
//		 cout << a[i] << " ";
//	 }
//	 cout << endl;
//		
//	///cout <<<< endl;
//
//	//Solution s;
//	//s.sortColors(nums);
//	//for (auto e : nums)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//	system("pause");
//}

//int partition(vector<int>&a, int l, int r)
//{
//	int prev = l - 1;
//	for (int i = l; i < r; i++)
//	{
//		if (a[i] < a[r])
//		{
//			if (++prev != i)
//			{
//				swap(a[prev], a[i]);
//			}
//		}
//	}
//	swap(a[++prev], a[r]);
//	//cout << prev << endl;
//	return prev;
//}
//int findKth(vector<int> a, int n, int K) {
//	// write code here
//	int l = 0;
//	int r = n - 1;
//	if (n == 0)
//		return 0;
//	int index = partition(a, l, r);
//	while (index != K - 1)
//	{
//		if (index > K - 1)
//		{
//			index = partition(a, l, index - 1);
//		}
//		else
//		{
//			index = partition(a, index + 1, r);
//		}
//	}
//	return a[index];
//}
//
//int main(){
//	vector<int> v = { 2, 3, 5, 1, 5 };
//	cout << findKth(v, 5, 3);
//	system("pause");
//}


//class A
//{
//public:
//	virtual void f()
//	{
//		cout << "A()" << endl;
//	}
//	int A_s = 100;
//};
//class B : public A
//{
//public:
//	void f()
//	{
//		cout << "B()" << endl;
//	}
//	int B_s = 200;
//	int B_ss = 300;
//};

class B
{
public:
	int m_iNum;
	int k1 = 10;
	virtual void foo()
	{

	}
};

class D : public B
{
public:
	char* m_szName[100];
	int k2 = 20;
	void foo();
};
void test1()
{
	B * pb = new B();
	D* pd1 = static_cast<D*>(pb);
	D* pd2 = dynamic_cast<D*>(pb);

	pd1->k2 = 120;
	cout << pd1->k2 << endl;
	//cout << pb-> << endl;
	//cout << pd2->k2 << endl;
	if (pd2 == nullptr)
		cout << "!!" << endl;
}


#include <vector> 
class Base
{
public:
	virtual void f()
	{
		cout << "Base::f" << endl;
	}
	void f1()
	{
		cout << "Base::f1" << endl;
	}
private:
	double x;
	double y;
};
class Derived : public Base
{
public:
	virtual void f() 
	{ 
		cout << "Derived::f" << endl;
	}
	virtual void k()
	{
		cout << "Derived::k" << endl;
	}
};

class Base1
{
public:
	virtual void g()
	{
		cout << "Base1::g" << endl;
	}
	void g1()
	{
		cout << "Base1::g1" << endl;
	}
};

class Derived1 : public Base, public Base1
{
public:
	virtual void f()
	{
		cout << "Derived1::f" << endl;
	}
	virtual void h()
	{
		cout << "Derived1::h" << endl;
	}
};

int main()
{

	Base * pD = new Derived;

	Derived* pD1 = dynamic_cast<Derived*>(pD);
	pD1->f();
	pD1->f1();
	pD1->k();

	Derived* pD2 = static_cast<Derived*>(pD);
	pD2->f();
	pD2->f1();
	pD2->k();



	system("pause");

}

