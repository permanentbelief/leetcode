//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int jump(vector<int> nums) {
//		if (nums.size() == 1)
//			return 0;
//		int reach = 0;
//		int nextreach = nums[0];
//		int step = 0;
//
//		for (int i = 0; i < nums.size(); i++)
//		{
//			nextreach = max(i + nums[i], nextreach);
//			if (nextreach >= nums.size() - 1)
//				return step + 1;
//			if (i == reach)
//			{
//				++step;
//				reach = nextreach;
//			}
//
//
//		}
//
//		return step;
//	}
//};
//int main()
//{
//	Solution s;
//
//	s.jump({ 2, 3, 1, 1, 4 });
//
//}