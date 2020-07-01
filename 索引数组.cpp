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
//void merge(vector<int>& nums, int left, int right)
//{
//	if (left >= right)
//		return;
//	int mid = (left + right) / 2;
//	merge(nums, left, mid);
//	merge(nums, mid + 1, right);
//
//	int i = left;
//	int j = mid + 1;
//	int k = left;
//	while (i <= mid && j <= right)
//	{
//		if (nums[index[i]] <= nums[index[j]])
//		{
//			helper[k++] = index[j++];
//		}
//		else
//		{
//			count[index[i]] += right - j + 1;
//			helper[k++] = index[i++];
//		}
//	}
//	while (i <= mid)
//	{
//		helper[k++] = index[i++];
//	}
//	while (j <= right)
//	{
//		helper[k++] = index[j++];
//	}
//
//	for (int i = left; i <= right; i++)
//	{
//		index[i] = helper[i];
//	}
//}
//vector<int> index;
//vector<int> helper;
//vector<int> count;
//
//vector<int> countSmaller(vector<int>& nums) {
//
//	int n = nums.size();
//	index.resize(n); //索引数组
//	helper.resize(n);
//	count.resize(n);
//	for (int i = 0; i < nums.size(); i++)
//	{
//		index[i] = i;
//	}
//	merge(nums, 0, n - 1);
//	return count;
//}
//
//};
//int main()
//{
//	Solution s;
//	vector<int> v = { 5, 2, 1, 6 };
//	s.countSmaller(v);
//
//	
//	system("pause");
//}


#include <map>
vector<int> findRightInterval(vector<vector<int>>& in) {
	if (in.empty())
	{
		return{};
	}
	int n = in.size();
	vector<pair<int, int>> vp(n);
	vector<int> v(n);
	map<pair<int, int>, int> maps;
	for (int i = 0; i < n; i++)
	{
		vp[i] = { in[i][0], in[i][1] };
		maps[vp[i]] = i;
	}

	sort(vp.begin(), vp.end(), [](pair<int, int> ap1, pair<int, int> ap2)
	{
		return  ap1.first < ap2.first;//ap1.second < ap2.second;
	});

	int st = -1e9;
	int ed = -1e9;

	for (int i = 0; i < n; i++)
	{
		//找第一个vp[i]的first 大于等于此second
		int target = vp[i].second;
		int l = 0;
		int r = n  - 1;
		while (l < r)
		{
			int mid = (l + r) / 2;
			if (vp[mid].first >= target)
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		if (l == n || l == 0) v[maps[vp[i]]] = -1;
		else  v[maps[vp[i]]] = maps[vp[l]];
	}
	return v;
}

bool isPerfectSquare(int num) {
	int  l = 1;
	int r = num;
	while (r > l)
	{
		int mid = (l + r) / 2;
		if (mid* mid > num)
			r = mid;
		else if (mid*mid == num)
			return true;
		else
			l = mid + 1;
	}
	return false;
}
//int main()
//{
//	/*vector<int> v = { 2,3,5};
//	vector<vector<int>> vv = { { 3, 4 }, { 2, 3 }, { 1, 2 } };*/
//	cout << isPerfectSquare(16);
//	//findRightInterval(vv);
//	system("pause");
//}