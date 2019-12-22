//#define _CRT_SECURE_NO_WARNINGS 1 
//
//// ¶þ·Ö·¨
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//	int missingNumber(vector<int>& nums) {
//		sort(nums.begin(), nums.end());
//
//		// 0 1 2 3 4 5 7 8
//		// 0 1 2 3 4 5 6 7
//		int start = 0;
//		int end = nums.size() - 1;
//		while (start <= end)
//		{
//			int mid = (start + end) / 2;
//			if (nums[mid] != mid)
//			{
//				if (mid == 0 || nums[mid - 1] == mid - 1)
//				{
//					return mid;
//				}
//				end = mid - 1;
//			}
//			else
//			{
//				start = mid + 1;
//			}
//		}
//		if (start == nums.size())
//		{
//			return nums.size();
//		}
//	}
//};
//int main()
//{
//	Solution s;
//	vector<int> str;
//	str.push_back(0);
//
//	str.push_back(1);
//	str.push_back(2);
//	str.push_back(3);//0 1 2 3 4 5 7 8
//	str.push_back(4);
//	str.push_back(5);
//	str.push_back(7);
//	str.push_back(8);
//	cout << s.missingNumber(str) << endl;
//	system("pause");
//}