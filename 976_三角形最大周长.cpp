//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	bool Angle_Valued(int num1, int num2, int num3)
//	{
//		if (num1 + num2 > num3 && num1 + num3 > num2 && num3 + num2 > num1)
//			return true;
//		return false;
//	}
//	int largestPerimeter(vector<int>& A) {
//		if (A.size() < 3)
//			return 0;
//		int max = 0;
//		for (int i = 0; i < A.size(); i++)
//		{
//			for (int j = i + 1; j < A.size(); j++)
//			{
//				for (int k = j + 1; k < A.size(); k++)
//				{
//					if (Angle_Valued(A[i] , A[j] ,A[k]))
//						max = (max>A[i] + A[j] + A[k]) ? max : (A[i] + A[j] + A[k]);
//				}
//			}
//		}
//		if (max == 0)
//			return 0;
//		return max;
//
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int> v;
//	v.push_back(2);
//	v.push_back(2);
//	v.push_back(1);
//	cout << s.largestPerimeter(v) << endl;
//	system("pause");
//}