//#define _CRT_SECURE_NO_WARNINGS 1 
//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
//		vector<int> input;
//		if (queries.empty())
//			return input;
//		int sum = 0;
//		for (int i = 0; i < A.size(); i++)
//		{
//			if (A[i] % 2 == 0)
//				sum += A[i];
//		}
//		int _sum = sum;
//		for (int i = 0; i < queries.size(); i++)
//		{
//		
//			int prev = A[queries[i][1]];
//			A[queries[i][1]] += queries[i][0];
//			if (prev % 2 != 0 && queries[i][0] % 2 != 0) // 原来的数是奇数 加上的数还是奇数
//				_sum += A[queries[i][1]];
//			else if (prev % 2 == 0 && queries[i][0] % 2 == 0) // 原来的数是偶数， 加上的数是偶数
//				_sum += queries[i][0];
//			else if (prev % 2 == 1 && queries[i][0] % 2 == 0) //原来的数是奇数， 加上的数是偶数
//				_sum = _sum;
//			else if (prev % 2 == 0 && queries[i][0] % 2 != 0) //原来的数是偶数， 加上的数是奇数
//				_sum -= prev;
//
//			input.push_back(_sum);
//		}
//		return input;
//	}
//};
//int main()
//{
//	Solution A;
//	vector<vector<int>> v;
//	vector<int> v_(2,0);
//	v_[0] = 1;
//	v_[1] = 0;
//	vector<int> v__(2, 0);
//	v__[0] = -3;
//	v__[1] = 1;
//	v.push_back(v_);
//	v.push_back(v__);
//	vector<int> B;
//	B.push_back(1);
//	B.push_back(2);
//	B.push_back(3);
//	B.push_back(4);
//	vector<int> a;
//	 a = A.sumEvenAfterQueries(B,v);
//	system("pause");
//
//
//
//}