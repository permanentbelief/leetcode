#define _CRT_SECURE_NO_WARNINGS 1 

#include <functional>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>
#include <stack>
#include <queue>
typedef long long ll;

using namespace std;

int shortestSubarray(vector<int>& A, int K) {
	deque<pair<int, int>> dq;
	dq.push_back(pair<int, int>(-1, 0));
	int minLen = INT_MAX;
	int sum = 0;
	for (int i = 0; i < A.size(); i++)
	{
		sum += A[i];
		while (dq.size() && sum <= dq.back().second)
			dq.pop_back();
 		dq.push_back(pair<int, int>{i, sum});
		while (sum - dq.front().second >= K)
		{
			minLen = min(minLen, i - dq.front().first);
			dq.pop_front();
		}
	}
	return minLen == INT_MAX ? -1 : minLen;
}
int main()
{
	vector<int> v = {  140,-300,50 };
	shortestSubarray(v, 150);

	system("pause");
}

//
//const int N = 550;
//const int K = 550;
//
//ll n, m, k;
//ll c;
//ll a[N];
//pair<int, int> p[N];
//ll index;
//
//bool check(int mid) 
//{
//	index = 0;
//	ll sum = 0;
//	int ant = 1;
//	p[index].first = 1;
//	for (int i = 1; i <= m; i++)
//	{
//		if (sum + a[i] <= mid)
//		{
//			sum += a[i];
//		}
//		else
//		{
//			p[index].second = a[i - 1];
//			sum = a[i];
//			p[++index].first = a[i];
//			ant++;
//		}
//	}
//	p[index].second = a[m];
//
//	return ant <= k;
//}
//
//int main()
//{
//	cin >> m >> k;
//	int ans = 0;
//	ll r = 0;
//	ll l = INT_MAX;
//	for (int i = 1; i <= m; i++)
//	{
//		cin >> a[i];
//		l = min(l, a[i]);
//		r += a[i];
//
//	}
//	
//
//	while (l <= r)
//	{
//		ll mid = (l + r) / 2;
//		if (check(mid))
//		{
//			r = mid - 1;
//		}
//		else
//		{
//			l = mid + 1;
//		}
//	}
//	cout << l << endl;
//	cout << r << endl;
//	cout << ans << endl;
//	/*check(l);
//
//	for (int i = 0; i <= index; i++)
//	{
//		cout << p[i].first << " " << p[i].second << endl;
//	}*/
//	system("pause");
//}
//
//
//
///*
//9 3
//1 7 3 2 1 4 9 8 3
//
//
//14
//*/