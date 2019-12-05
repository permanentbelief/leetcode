#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	bool isSubsequence(string s, string t) {

		//通过不了测试用例

		//if (s.empty() && t.empty())
		//	return true;
		//if (s.empty() && !t.empty())
		//	return true;
		//if (!s.empty() && t.empty())
		//	return false;

		//string v;
		//for (int i = 0; i < t.size(); i++)
		//{
		//	for (int j = 0; j < s.size(); j++)
		//	{
		//		if (t[i] == s[j])
		//		{
		//			v.push_back(t[i]); //0 2 7
		//			break;
		//		}
		//	}

		//}
		//if (v.size() != s.size())
		//{
		//	return false;
		//}
		//for (int i = 0; i < v.size(); i++)
		//{
		//	if (v[i] != s[i])
		//		return false;
		//}
		//return true;
		int i = 0;
		int j = 0;
		while (i < s.size()){
			while (j < t.size() && t[j] != s[i])
			{
				++j;
			}
			if (j >= t.size()) return false;
			++j;
			++i;
		}
		return true;
	}
};
int main()
{
	Solution a;
	cout << a.isSubsequence("leeeeetcode", "yyyyyyyyleyyyyyyyyyytcode") << endl;
	system("pause");
} 