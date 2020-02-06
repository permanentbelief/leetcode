#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <functional>

using namespace std;
struct CmpByValueLess
{
	bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs)
	{
		return lhs.second < rhs.second;
	}
};
vector<int> topKFrequent(vector<int>& nums, int k) {
	// sort(nums.begin(),nums.end());
	vector<int> v;
	vector<int> vv;
	if (nums.empty())
		return v;
	map<int, int> m;
	for (int i = 0; i < nums.size(); i++)
	{
		++m[nums[i]];
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, CmpByValueLess> pq;
	/*for (auto iter = m.begin(); iter != m.end(); ++iter)
	{
		pq.push(*iter);
	}*/
	for (auto e : m)
	{
		pq.push(e);
	}
	vector<int> res(k);
	for (int i = 0; i < k; i++)
	{
		res[i] = pq.top().first;
		pq.pop();
	}
	return res;

}


	//方法二
//struct CmpByValue
//{
//	bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs)
//	{
//		return lhs.second > rhs.second;
//	}
//};
//
//struct Cmp
//{
//	bool operator() (const int& a, const int& b)
//	{
//		return a > b;
//	}
//};
//vector<int> topKFrequent(vector<int>& nums, int k)
//{
//	map<int, int> m;
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		++m[nums.at(i)];
//	}
//	vector<pair<int, int>>v(m.begin(), m.end());
//	sort(v.begin(), v.end(), CmpByValue()); //从大到小
//
//	
//	vector<int> k_frequent(k);
//	for (int i = 0; i < k; i++)
//	{
//		k_frequent.at(i) = v.at(i).first;
//	}
//
//	return k_frequent;
//
//
//}
int main()
{
	vector<int> nums = {
		4, 1, -1, 2, -1, 2, 3 };
	vector<int> map = topKFrequent(nums, 2);

	system("pause");
}