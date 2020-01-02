//#define _CRT_SECURE_NO_WARNINGS 1 
//
//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
////vector<int>& Uniqe(vector<int>& nums1)  //  去重的函数
////{
////	sort(nums1.begin(), nums1.end());
////	
////	for (int i = 0; i < nums1.size()-1; i++)
////	{
////		if (nums1[i] == nums1[i + 1])
////		{
////			for (int j = i; j < nums1.size() - 1; j++)
////			{
////				nums1[j] = nums1[j + 1];
////			}
////			nums1.erase(--nums1.end());
////			i -= 1;
////		}
////	}
////	return nums1;
////	
////}
////int main()
////{
////	vector<int> v = { 1,1 };
////	vector<int> outcome = Uniqe(v);
////	for (int i = 0; i < outcome.size(); i++)
////	{
////		cout << outcome[i] << endl;
////	}
////	system("pause");
////}
//
//// 正确 还可以扔到set中。
//class Solution {
//public:
//	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//		vector<int> B;
//		if (nums1.empty() || nums2.empty() || (nums1.empty() && nums2.empty()))
//			return B;
//		sort(nums1.begin(), nums1.end());
//		sort(nums2.begin(), nums2.end());
//		for (int i = 0; i < nums1.size() - 1; i++)
//		{
//			if (nums1[i] == nums1[i + 1])
//			{
//				for (int j = i; j < nums1.size() - 1; j++)
//				{
//					nums1[j] = nums1[j + 1];
//				}
//				nums1.erase(--nums1.end());
//				i -= 1;
//			}
//		}
//		for (int i = 0; i < nums2.size() - 1; i++)
//		{
//			if (nums2[i] == nums2[i + 1])
//			{
//				for (int j = i; j < nums2.size() - 1; j++)
//				{
//					nums2[j] = nums2[j + 1];
//				}
//				nums2.erase(--nums2.end());
//				i -= 1;
//			}
//		}
//		for (int i = 0; i < nums1.size(); i++)
//		{
//			for (int j = 0; j < nums2.size(); j++)
//			{
//				if (nums1[i] == nums2[j])
//					B.push_back(nums1[i]);
//			}
//		}
//		return B;
//	}
//};
//int main()
//{
//	Solution s;
//	vector<int> num1 = { 1, 2, 2, 1 };
//	vector<int> num2 = { 2, 2 };
//	vector<int> num3 = s.intersection(num1, num2);
//	system("pause");
//}