#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
//
//class Solution {
//public:
//
//	void merge(vector<int>& nums, int l, int r)
//	{
//		if (l >= r)
//			return;
//		int mid = (l + r) / 2;
//		merge(nums, l, mid);
//		merge(nums, mid + 1, r);
//		int i = l;
//		int j = mid + 1;
//		int k = l;
//		vector<int> helper(r - l + 1);
//
//		while (i <= mid && j <= r)
//		{
//			if (nums[index[i]] <= nums[index[j]])
//			{
//				helper[k++] = index[j++];
//			}
//			else
//			{
//				count[index[i]] += r - j + 1;
//				helper[k++] = index[i++];
//			}
//		}
//
//		while (i <= mid)
//		{
//			helper[k++] = index[i++];
//		}
//		while (j <= r)
//		{
//			helper[k++] = index[j++];
//		}
//
//		for (int i = l; i <= r; i++)
//		{
//			index[i] = helper[i];
//		}
//	}
//
//	vector<int> count;
//	vector<int> index;
//
//	vector<int> countSmaller(vector<int>& nums) {
//		if (nums.size() == 0)
//			return count;
//		int n = nums.size();
//		count.resize(n);
//		index.resize(n);
//		for (int i = 0; i < n; i++)
//		{
//			index[i] = i;
//		}
//
//		merge(nums, 0, nums.size() - 1);
//
//		return count;
//	}
//};
//int main()
//{
//	Solution s;
//	vector<int> v = { 5, 2, 6, 1 };
//	s.countSmaller(v);
//	system("pause");
//}

//class B{
//public:
//	B()
//	{
//		cout << "B:B() is called" << endl;
//	}
//	B(int x)
//	{
//		cout << "B:B(x) is called" << endl;
//		x = a;
//	}
//private:
//	int a;
//};
//class A{
//public:
//	A(int x)
//		:b(B(x))
//	{
//		a = x;
//		//b = B(x);
//		cout << "A:A() is called" << endl;
//	}
//	~A()
//	{
//
//	}
//private:
//	int a;
//	B b;
//};
//int main()
//{
//	A t(1);
//	system("pause");
//	return 0;
//}


class Solution {
public:

	struct node
	{
		int start;
		int end;
		int pro;
		bool operator<(node& n)
		{
			return end < n.end;
		}
	};
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		int n = startTime.size();
		if (n == 0)
			return 0;
		vector<node> v(n);

		for (int i = 0; i < n; i++)
		{
			v[i].start = startTime[i];
			v[i].end = endTime[i];
			v[i].pro = profit[i];
		}

		sort(v.begin(), v.end());
		vector<int> dp(n);
		dp[0] = profit[0];

		for (int i = 1; i < n; i++)
		{
			int pre = b(v, i) - 1;
			if (pre >= 0)
				dp[i] = max(dp[pre] + v[i].pro, dp[i - 1]);
			else
				dp[i] = max(dp[i - 1], v[i].pro);
		}
		return dp[n - 1];

	}
	// 选出第一个 大于等于 v[cur].start的位置
	int b(vector<node>& v, int cur)
	{
		int l = 0;
		int r = v.size() - 1;
		while (l < r)
		{
			int mid = (l + r) / 2;
			if (v[mid].end > v[cur].start)
				r = mid;
			else
				l = mid + 1;
		}
		return l;
	}
};
int lcm(int a, int b) //最小公倍数
{
	int sum = a*b;
	while (b)
	{
		int tmp = a;
		a = b;
		b = tmp%b;
	}
	return sum / a;
}





class Solution1 {
public:
	int maxDistance(vector<int>& a, int m) {
		int l = 0;
		int r = 1e9;
		sort(a.begin(), a.end());
		r = min(r, a.back() - a.front());

		//最小值 最大
		while (l < r)
		{
			int mid = (l + r ) / 2;
			int pre = a[0];
			int cnt = 1;
			for (int i = 1; i< a.size(); i++)
			{
				if (a[i] - pre >= mid)
				{
					cnt++;
					pre = a[i];
				}
			}
			if (cnt >  m) //如果cnt >= m 说明 mid过小 要增大
			{
				l = mid + 1;
			}
			else
			{
				r = mid;
			}
		}
		return l;

	}
};



	int main()
	{
		vector<int> color = { 1, 1, 2, 1, 3, 2, 2, 3, 3 };
		vector<vector<int>> queries = { { 1, 3 }, { 2, 2 }, { 6, 1 } };


		int l = INT_MAX;
		int r = 0;
		for (int i = 0; i < color.size(); i++)
		{
			r = max(r, color[i]);
			l = min(l, color[i]);
		}
		vector<vector<int>> g(r + 1);
		for (int i = 0; i < color.size(); i++)
		{
			g[color[i]].push_back(i);
		}
		vector<int> dp;
		for (int i = 0; i < queries.size(); i++)
		{
			bool flag1 = false;
			int k = queries[i][1];
			int target = queries[i][0];
			if (g.size() < k)
			{
				cout << -1 << endl;
				return 0;
			}
			int l = 0;
			int r = g[k].size() - 1;
			while (l < r) //大于等于 queries[i][0]的第一个数
			{
				int mid = (l + r) / 2;
				if (g[k][mid] >= target)
					r = mid;
				else
					l = mid + 1;
			}
			if (!(g[k][l] >= target))
			{
				flag1 = true;
			}
			int rr = r;  //小于等于 queries[i][0]的最后一个数
			l = 0;
			r = g[k].size() - 1;
			while (l < r)
			{
				int mid = (l + r + 1) / 2;
				if (g[k][mid] >= target)
					r = mid - 1;
				else
					l = mid;
			}
			int ll = l;
			if (!(g[k][l] <= target))
			{
				if (flag1 == true)
				{
					cout << -1;
					return 0;
				}
			}
			dp.push_back(min(abs(target - g[k][ll]), abs(g[k][rr] - target)));


		}
		for (int i = 0; i < dp.size(); i++)
		{
			cout << dp[i] << " ";
		}
		cout << endl;
		system("pause");

}