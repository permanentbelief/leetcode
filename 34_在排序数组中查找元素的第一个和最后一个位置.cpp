//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
////��ȷ
//class Solution {
//public:
//	vector<int> searchRange(vector<int>& nums, int target) {
//
//		//���ҵ�һ��λ�õ��±�
//		//�������һ��λ�õ��±�
//		vector<int> ans = { -1, -1 };
//		if (nums.empty())
//			return ans;
//		int left_value = nums[0];
//		int right_value = nums[nums.size() - 1];
//		if (left_value > target || right_value < target)
//			return ans;
//		//���ö����ҵ�һ��ֵΪtarget���±�
//		int left = 0;
//		int right = nums.size() - 1;
//		while (left <= right)
//		{
//			int mid = left + (right - left) / 2;
//			if (nums[mid] > target)
//			{
//				right = mid - 1;
//			}
//			else if (nums[mid] < target)
//			{
//				left = mid + 1;
//			}
//			else 
//			{
//				if (mid == 0 || nums[mid-1] != target)
//				{
//					ans[0] = mid;
//					break;
//				}
//				else
//				{
//					right = mid - 1;
//				}
//			}
//
//		}
//
//		left = 0;
//		right = nums.size() - 1;
//		while (left <= right)
//		{
//			int mid = left + (right - left) / 2;
//			if (nums[mid] > target)
//			{
//				right = mid - 1;
//			}
//			else if (nums[mid] < target)
//			{
//				left = mid + 1;
//			}
//			else
//			{
//				if (mid == nums.size()-1 || nums[mid + 1] != target)
//				{
//					ans[1] = mid;
//					break;
//				}
//				else
//				{
//					left = mid + 1;
//				}
//			}
//
//		}
//		return ans;
//		
//	}
//};
//int main()
//{
//	Solution s;
//	vector<int> v = { 5, 7, 7, 8, 8, 10 };
//	int k = 6;
//
//	vector<int> sv = s.searchRange(v, k);
//	for (int i = 0; i < sv.size(); i++)
//	{
//		cout << sv[i] << " ";
//	}
//	system("pause");
//}
//
//// 5 7 7 8 8 10
//// 