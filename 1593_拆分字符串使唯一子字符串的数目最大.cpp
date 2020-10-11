#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:

	set<string> s;
	int max_ = 0;
	void dfs(string &str, string tmp, int t) // ×î´ó²ð·Ö
	{
		if (s.count(tmp))
		{
			return;
		}
		if (tmp != "")
			s.insert(tmp);
		if (t == str.size())
		{
			max_ = max(max_, (int)s.size());
			return;
		}

		for (int i = t; i < str.size(); i++)
		{
			tmp = str.substr(i, i - t + 1);
			dfs(str, tmp, i + 1);

		}
	}
	int maxUniqueSplit(string str) {
		int t = 0;
		dfs(str, "", t);

		return max_;
	}
};
int main()
{
	Solution s;
	string str = "ababccc";
	cout << s.maxUniqueSplit(str) << endl;

	system("pause");
}