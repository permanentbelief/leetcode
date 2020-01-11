//#define _CRT_SECURE_NO_WARNINGS 1 
//
//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	vector<vector<int>> out;
//	vector<int> ret;
//	vector<vector<int>> permuteUnique(vector<int>& nums) {
//		vector<bool> flag(nums.size(), false);
//		DFS(out, nums, flag);
//		//ШЅжи
//		sort(out.begin(), out.end());
//		out.erase(unique(out.begin(), out.end()), out.end());
//		return out;
//
//	}
//
//	void DFS(vector<vector<int>>&out, vector<int>& nums, vector<bool> flag)
//	{
//		if (nums.size() == ret.size())
//		{
//				out.push_back(ret);
//		}
//		else
//		{
//			for (int i = 0; i < nums.size(); i++)
//			{
//				if (flag[i] == 0)
//				{
//					ret.push_back(nums[i]);
//					flag[i] = 1;
//					DFS(out, nums, flag);
//					flag[i] = 0;
//					ret.pop_back();
//				}
//			}
//		}
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int> v = { 1, 1, 3 };
//	vector<vector<int>> vv = s.permuteUnique(v);
//	for (auto e : vv)
//	{
//		for (auto l : e)
//		{
//			cout << l << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//}