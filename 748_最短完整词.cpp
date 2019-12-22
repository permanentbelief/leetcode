//#define _CRT_SECURE_NO_WARNINGS 1 
//
//
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//class Solution {
//public:
//	bool V_Compare(string& s, string t) // t是str 短串 1 2 3  2 3  这里不能取t的引用
//	{
//		for (int i = 0; i < s.size(); i++)
//		{
//			for (int j = 0; j < t.size(); j++)
//			{
//				if (s[i] == t[j])
//				{
//					t.erase(j, 1);
//
//					break;
//				}
//			}
//		}
//		if (t.empty())
//			return true;
//		return false;
//
//	}
//	string shortestCompletingWord(string licensePlate, vector<string>& words) {
//		string str;
//		for (int i = 0; i < licensePlate.size(); i++)
//		{
//			if (licensePlate[i] >= 65 && licensePlate[i] <= 90)
//			{
//				str += licensePlate[i] + 32;
//			}
//			if (licensePlate[i] >= 97 && licensePlate[i] <= 122)
//			{
//				str += licensePlate[i];
//			}
//		}
//		string temp;
//		int min = 16;
//		for (int i = 0; i < words.size(); i++)
//		{
//			if (str.size() > words[i].size())
//				continue;
//			else
//			{
//				if (V_Compare(words[i], str))
//				{
//					if (words[i].size() < min)
//					{
//						min = words[i].size();
//						temp = words[i];
//
//					}
//
//
//				}
//			}
//		}
//		return temp;
//	}
//};
//int main()
//{
//	Solution s;
//	vector<string>words;
//	//push_back("suggest");
//	//words.push_back("letter");
//	//words.push_back("of");
//	words.push_back("husband");
//
//	//words.push_back("easy");
//	//words.push_back("education");
//	//words.push_back("drug");
//	//words.push_back("prevent");
//	//words.push_back("writer");
//	words.push_back("old");
//
//	string str("Ah71752");
//	cout << s.shortestCompletingWord(str, words) << endl;
//	system("pause");
//}
