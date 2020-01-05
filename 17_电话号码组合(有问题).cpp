//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//
////为什么 都打印两遍啊？？？
//class Solution {
//private:
//	vector<string> ret;
//	string str;
//public:
//	//ret 最终返回的string数组 
//	//digit 原来的数组
//	//out 每一次字符组合的字符串
//	void DFS(vector<string>& ret, string& digits, string& out, int curId, vector<bool>flag)
//	{
//		static string nums[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
//		if (curId == digits.size())
//		{
//			ret.push_back(out);
//			return;
//		}
//		else
//		{
//			for (int i = 0; i < digits.size(); i++)
//			{
//				if (flag[i] == 0)
//				{
//					for (auto&e : nums[digits[i] - '0'])
//					{
//						out += e;
//						flag[i] = 1;
//						DFS(ret, digits, out, curId + 1, flag);
//						flag[i] = 0;
//						out.pop_back();
//					}
//
//
//				}
//			}
//		}
//	}
//
//	vector<string> letterCombinations(string digits) {
//		vector<bool> flag(digits.size(), 0);
//		DFS(ret, digits, str, 0, flag);
//		return ret;
//
//	}
//};
//
//int main()
//{
//	Solution s;
//	string str = "22";
//	vector<string> vv = s.letterCombinations(str);
//	for (auto e : vv)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	system("pause");
//}