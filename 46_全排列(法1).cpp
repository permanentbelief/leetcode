//#define _CRT_SECURE_NO_WARNINGS 1 
//
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	vector<vector<int>> res;
//	vector<int>path;
// 	vector<vector<int>> permute(vector<int>& nums) {
//		vector<bool> flag(nums.size(), 0);
//		backtrack(nums, flag);
//		return res;
//	}
//	void backtrack(vector<int>& nums, vector<bool> flag)
//	{
//		if (path.size() == nums.size())
//			res.push_back(path);
//		else
//		{
//			for (int i = 0; i < nums.size(); i++)
//			{
//				/*
//				if(flag[i])
//				continue;
//				*/
//				if (flag[i] == 0)
//				{
//					path.push_back(nums[i]);
//					flag[i] = 1;
//					backtrack(nums, flag);
//					flag[i] = 0;
//					path.pop_back();
//				}
//
//			}
//		}
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int> v = { 1, 3 };
//	vector<vector<int>> vv = s.permute(v);
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