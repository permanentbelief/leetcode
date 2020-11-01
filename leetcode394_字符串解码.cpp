#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
//class Solution {
//public:
//	string decodeString(string s) {
//		string str;
//
//		int num = 0;
//		stack<int> si;
//		stack<string> ss;
//		string cur = "";
//		string result = "";
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (s[i] >= '0' && s[i] <= '9')
//			{
//				num = num * 10 + s[i] - '0';
//			}
//			else if (s[i] == '[')
//			{
//				si.push(num);
//				ss.push(cur);
//				num = 0;
//				cur.clear();
//			}
//			else if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
//			{
//				cur += s[i];
//			}
//			else if (s[i] == ']')
//			{
//				int k = si.top();
//				si.pop();
//				for (int i = 0; i < k; i++)
//				{
//					ss.top() += cur;
//				}
//				cur = ss.top();
//				ss.pop();
//			}
//			//string res;
//		}
//
//		return cur;
//	}
//};
//int main()
//{
//	
//	Solution s;
//	string str = "3[a2[c]]";
//	s.decodeString(str);
//
//	system("pause");
//}