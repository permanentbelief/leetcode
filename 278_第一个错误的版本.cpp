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
//		while (left < right) // ���ܴ��� =   �п���left=right=mid һֱѭ��������
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
//		return  right; //�������ѭ����ʱ�� left��right����ȵģ�����return left Ҳ����
//	}
//};
//int main()
//{
//	Solution s;
//	cout << s.firstBadVersion(4,5) << endl;
//	system("pause");
//}