//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//	vector<vector<int>> ans;
//	void permutation(vector<int> nums, int s, int e)
//	{
//		if (s == e)
//		{
//			ans.push_back(nums);
//			return;
//		}
//		for (int i = s; i <= e; i++)
//		{
//			swap(nums[i], nums[s]);
//			permutation(nums, s + 1, e);
//			swap(nums[i], nums[s]);
//		}
//	}
//	vector<vector<int>> permute(vector<int>& nums) {
//		permutation(nums, 0, nums.size() - 1);
//		return ans;
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int> v = { 1, 2, 3 };
//	vector<vector<int>> vv = s.permute(v);
//	for (int i = 0; i < vv.size(); i++)
//	{
//		for (int j = 0; j < vv[i].size(); j++)
//		{
//			cout << vv[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	system("pause");
//
//}