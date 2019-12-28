//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//using namespace std;
//class Solution {
//public:
//	bool isBadVersion(int version, int i)
//	{
//		if (i < version)
//			return false;
//		else 
//			return true;
//	}
//	int firstBadVersion(int version,int n) {
//		int left = 1;
//		int right = n;
//		while (left < right) // 不能带上 =   有可能left=right=mid 一直循环出不来
//		{
//			int mid = left + (right - left) / 2;
//			if (isBadVersion(version,mid))
//			{
//				right = mid;
//			}
//			else
//			{
//				left = mid + 1;
//			}
//		}
//		return  right; //最后跳出循环的时候 left和right是相等的，所以return left 也可以
//	}
//};
//int main()
//{
//	Solution s;
//	cout << s.firstBadVersion(4,5) << endl;
//	system("pause");
//}