//#define _CRT_SECURE_NO_WARNINGS 1 
//
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//
////  chars只能用一次
////class Solution {
////public:
////	int countCharacters(vector<string>& words, string chars) {
////		int count = 0;
////		vector<bool> flag(words.size(), false);
////		for (int i = 0; i < words.size(); i++)
////		{
////			//看词汇表中的每个单词是否符合
////			int count = 0;
////			for (int j = 0; j < words[i].size(); j++)
////			{
////
////				for (int k = 0; k < chars.size(); k++)
////				{
////					if (words[i][j] == chars[k])
////					{
////						count++;
////						break;
////					}
////
////				}
////			}
////			if (count == words[i].size())
////			{
////				flag[i] = true;
////			}
////
////		}
////		int sum = 0;
////		for (int i = 0; i < flag.size(); i++)
////		{
////			if (flag[i] == true)
////				sum += words[i].size();
////		}
////		return sum;
////	}
////};
//
//// 已AC过 ！
//class Solution {
//public:
//	int countCharacters(vector<string>& words, string chars) {
//		int count = 0;
//		
//		vector<bool> flag(words.size(), false);
//		for (int i = 0; i < words.size(); i++)
//		{
//			//看词汇表中的每个单词是否符合
//			int count = 0;
//			for (int j = 0; j < words[i].size(); j++)
//			{
//				string charstemp = chars;
//				for (int k = 0; k < charstemp.size(); k++)
//				{
//					if (words[i][j] == charstemp[k])
//					{
//						charstemp.erase(k, 1);
//						count++;
//						break;
//					}
//
//				}
//			}
//			if (count == words[i].size())
//			{
//				flag[i] = true;
//			}
//
//		}
//		int sum = 0;
//		for (int i = 0; i < flag.size(); i++)
//		{
//			if (flag[i] == true)
//				sum += words[i].size();
//		}
//		return sum;
//	}
//};
//int main()
//{
//	Solution s;
//	vector<string> vs{ "cat", "bt", "hat", "tree" };
//	string str = "atach"; 
//// q w 
//	//sort(str.begin(), str.end());
//	//cout << str << endl;
//	//for (int i = 0; i < str.size(); i++)
//	//{
//	//	if (str[i] == str[i + 1])
//	//	{
//	//		str.erase(i, 1);
//	//		i -= 1;
//	//	}
//	//}
//	//cout << str << endl;
//	//cout << str.size() << endl;
//	cout << s.countCharacters(vs, str) << endl;
//	system("pause");
//}