#define _CRT_SECURE_NO_WARNINGS 1 

//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//int n;
//int max_ = 0;
//void dfs(vector<vector<int>>&P, vector<vector<int>>& Q, vector<bool>& books, vector<int> v,  int res, int cur)
//{
//	if (cur == v.size())
//	{
//		/*
//		int res = 0;
//		for (int i = 0; i < v.size(); i++)
//		{
//			res += P[i][v[i]] * Q[v[i]][i];
//		}
//		*/
//		if (res > max_)
//			max_ = res;
//		return;
//	}
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (!books[i])
//		{
//			books[i] = true;
//			res += P[i][v[i]] * Q[v[i]][i];
//			dfs(P, Q, books, v, res, i + 1);
//			res -= P[i][v[i]] * Q[v[i]][i];
//			books[i] = false;
//		}
//	}
//}
//int main()
//{
//	cin >> n;
//	vector<vector<int>> P(n, vector<int>(n));
//	vector<vector<int>> Q(n, vector<int>(n));
//	
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> P[i][j];
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> Q[i][j];
//		}
//	}
//	//vector<vector<int>>&P, vector<vector<int>>& Q, vector<bool>& books, vector<int> v,  int res, int cur
//	vector<bool> books(n, false);
//	vector<int> v(n);
//	for (int i = 0; i < n; i++)
//	{
//		v[i] = i;
//	}
//	dfs(P, Q, books,v, 0, 0);
//	cout << max_ << endl;
//	system("pause");
//}

//
//const int N = 600;
//const int  M = 5e4 + 1000;
//// 只要数组 越界什么错误都可能会发生
//int h[N], e[M], ne[M], idx;
//int match[N]; // 每一个妹子 对应的男生
//bool st[N]; // 判重
//
//int n1, n2, m;
//
//void add(int a, int b)
//{
//	e[idx] = b;
//	ne[idx] = h[a];
//	h[a] = idx++;
//}
//bool find(int x)
//{
//	for (int i = h[x]; i != -1; i = ne[i])
//	{
//		int j = e[i];
//		if (!st[j])
//		{
//			st[j] = true;
//			if (match[j] == 0 || find(match[j]))
//			{
//				match[j] = x;
//				return true;
//			}
//		}
//	}
//	return false;
//}
//int main()
//{
//	cin >> n1 >> n2 >> m;
//	memset(h, -1, sizeof h);
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		add(a, b);
//	}
//	int res = 0;
//	
//	for (int i = 1; i <= n1; i++)
//	{
//		memset(st, false, sizeof st);
//		if (find(i))
//			res++;
//	}
//	cout << res << endl;
//	//system("pause");
//}

