//#define _CRT_SECURE_NO_WARNINGS 1 
//
//
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//
///*
//1.�����Ժ�ʹ��unique()������unique�����Ƚϵ�ʱ���ڵ�����Ԫ�أ��ظ��ķŵ�vectorβ��
//
//sort(vector.begin(),vector.end());
//
//vector.erase(unique(vector.begin(),vector.end()), vector.end());
//
////unique()�������ظ���Ԫ�طŵ�vector��β�� Ȼ�󷵻�ָ���һ���ظ�Ԫ�صĵ����� ����erase�������������Ԫ�ص����Ԫ�ص����е�Ԫ��
//
//*/
//int  main()
//{
//	vector<int> v = { 1, 3, 3, 4, 4, 4, 7, 7, 8, 1 };
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	sort(v.begin(), v.end());
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	auto a = unique(v.begin(), v.end());
//	v.erase(a, v.end());
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	system("pause");
//}