//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//	vector<int> sortArrayByParityII(vector<int>& A) {
//		int j = 1;
//		for (int i = 0; i < A.size(); i += 2)
//		{
//			if (A[i] % 2 != 0)  // 偶数位置不是偶数
//			{
//				while (A[j] % 2 != 0) // 找 奇数位置不是奇数
//				{
//					j += 2;
//				}
//				swap(A[i], A[j]);
//			}
//	
//		}
//		return A;
//
//	}
//};
//int main()
//{
//	Solution s;
//	vector<int> v = {2, 3};
//	s.sortArrayByParityII(v);
//
//}