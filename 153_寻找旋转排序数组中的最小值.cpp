//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//class Solution {
//public:
//	static int findMin(vector<int>& nums) {
//
//		int left = 0, right = nums.size() - 1, mid;
//		while (left < right) {
//			mid = (left + right) / 2;
//			if (nums[mid] > nums[mid + 1]) 
//				return nums[mid+1];
//			if (nums[mid] > nums[right])
//				left = mid;
//			else 
//				right = mid;   // nums[mid] <= nums[right];
//		}
//		return nums[left];
//	}
//
//};
//
//int main()
//{
//	vector<int> nums = {1};
//	cout << Solution::findMin(nums) << endl;
//	system("pause");
//}