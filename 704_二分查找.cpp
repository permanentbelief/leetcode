//#define _CRT_SECURE_NO_WARNINGS 1 
//#include<iostream>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//	int search(vector<int>& nums, int target) {
//		int start = 0;
//		int end = nums.size() - 1;
//		while (start <= end)
//		{
//			int mid = start - (start - end) / 2;
//			if (nums[mid] == target)
//				return mid;
//			else if (nums[mid] < target)
//			{
//				start = mid + 1;
//			}
//			else
//			{
//				end = mid - 1;
//			}
//						// 我太菜了 ，这些什么start++  end-- 啊！！。。。
//		}
//		return -1;
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int> v;
//	v.push_back(2);
//	v.push_back(5);
//	cout << s.search(v, 5) << endl;
//	system("pause");
//}