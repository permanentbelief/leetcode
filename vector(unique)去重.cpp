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
//1.排序以后使用unique()函数：unique函数比较的时相邻的两个元素，重复的放到vector尾部
//
//sort(vector.begin(),vector.end());
//
//vector.erase(unique(vector.begin(),vector.end()), vector.end());
//
////unique()函数将重复的元素放到vector的尾部 然后返回指向第一个重复元素的迭代器 再用erase函数擦除从这个元素到最后元素的所有的元素
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