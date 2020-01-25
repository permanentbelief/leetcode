//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <vector>
//#include <stack>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> dailyTemperatures(vector<int>& T) {
//		stack<int> s;
//		vector<int> res(T.size(), 0);
//		for (int i = 0; i < T.size(); i++)
//		{
//			while (!s.empty() && T[s.top()] < T[i])
//			{
//				res[s.top()] = (i - s.top());
//				s.pop();
//			}
//			s.push(i);
//		}
//		return res;
//	}
//};
//int main()
//{
//	Solution s;
//	vector<int> v = { 73, 74, 75, 71, 69, 72, 76, 73 };
//	 s.dailyTemperatures(v);
//}