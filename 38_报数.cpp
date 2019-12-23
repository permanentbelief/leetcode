//#define _CRT_SECURE_NO_WARNINGS 1 

//class Solution {
//public:
//	string countAndSay(int n) {
//		string s = "1";
//		for (int i = 1; i < n; i++)  //注意！！！ 不能=n 是对n-1的 那一行数字做解析
//		{
//			string temp;
//			int ans = 1;  // ans一开始就是等于1 因为单个数出现的次数就是1
//			for (int j = 0; j < s.size(); j++)
//
//			if (s[j + 1] == s[j]) //s[j+1]是什么？？  越界了
//			{
//				ans++;
//			}
//			else
//			{
//				temp += ans + '0';
//				temp += s[j];
//				ans = 1; // 要给1计算下一次的有没有重复的数
//			}
//			s = temp;
//		}
//		return s;
//	}
//
//};
/*Solution s;
	cout << s.countAndSay(2) << endl;
	cout << endl;*/


//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	string s("abcde");
//	s[s.size()] = 'A';
//	for (int i = 0; i <= s.size(); i++)
//	{
//		cout << s[i] << endl;
//	}
//	s[s.size() + 1] = 'A';
//
//
//	system("pause");
//}