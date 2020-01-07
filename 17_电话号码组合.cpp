//#define _CRT_SECURE_NO_WARNINGS 1 
//
//
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//class Solution {
//
//public:
//	//ret 最终返回的string数组 
//	//digit 原来的数组
//	//out 每一次字符组合的字符串
//	void DFS(vector<string>& ret, string& digits, string&out, int curId)
//	{
//		static string nums[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
//		if (curId == digits.size())
//		{
//			ret.push_back(out);
//			return;
//		}
//		//当前数字所对应的字符串
//		string curdigitMap = nums[digits[curId] - '0'];
//		//尝试给第curId个盒子放入数字对应的每一个字符
//		for (auto ch : curdigitMap)
//		{
//			DFS(ret, digits, out + ch, curId + 1);
//		}
//	}
//
//	vector<string> letterCombinations(string digits) {
//		vector<string> ret;
//		string out;
//		if (digits.empty())
//			return ret;
//		DFS(ret, digits, out, 0);
//		return ret;
//
//	}
//};
//
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