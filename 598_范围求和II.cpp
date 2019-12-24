//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>  
//#include <vector>
//#include  <string>
//#include <algorithm>
//
//using namespace std;
//                          // 空间复杂度 和时间复杂度太大 AC不过
//class Solution {
//public:
//	int maxCount(int m, int n, vector<vector<int>>& ops) {
//		vector<vector<int>> v(m, vector<int>(n, 0));
//		if (ops.empty())
//			return m*n;
//		for (int i = 0; i < ops.size(); i++)
//		{
//			for (int j = 0; j < ops[i][0]; j++)
//			{
//				for (int k = 0; k < ops[i][1]; k++)
//				{
//					v[j][k]++;
//				}
//			}
//		}
//		int max = ops[0][0];
//		for (int i = 0; i < ops.size(); i++)
//		{
//			for (int j = 0; j < ops[0].size(); j++)
//			{
//				if (ops[i][j] > max)
//					max = ops[i][j];
//			}
//		}
//		int count = 0;
//		for (int i = 0; i < ops.size(); i++)
//		{
//			for (int j = 0; j < ops[0].size(); j++)
//			{
//				if (ops[i][j] == max)
//					count++;
//			}
//		}
//		return max;
//
//	}
//};
//int main()
//{
//	vector<vector<int>> ops;
//	ops.push_back({ 2, 2 });
//	ops.push_back({ 3, 3 });
//	Solution s;
//	cout << s.maxCount(3, 3, ops) << endl;
//	system("pause");
//}