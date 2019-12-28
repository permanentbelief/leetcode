//#define _CRT_SECURE_NO_WARNINGS 1 
//
//
//#include<iostream>
//#include <vector>
//using namespace std; 
//
//// 好方法 AC过
//class Solution {
//public:
//	void rotate(vector<int>& nums, int k) {
//		reverse(nums.begin(), nums.end());
//		reverse(nums.begin(), nums.begin() + k%nums.size());
//		reverse(nums.begin() + k%nums.size(), nums.end());
//	}
//};
//
//int main()
//{
//	//vector<vector<int>>  v = { { 2, 1, 1 }, { 0, 1, 1 }, { 1, 0, 1 } };
//	//Solution s;
//
//
//	vector<int> k = { 1, 4, 6, 8, 9, 3 };
//	Solution s;
//	s.rotate(k, 3);
//	system("pause");
//
//}