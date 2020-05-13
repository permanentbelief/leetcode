#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


//5 最长回文子串的方法和这个一模一样
int countSubstrings(string s) {
	if (s.empty())
		return 0;
	int n = s.size();
	int cnt = 0;
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		dp[i][i] = 1;
		cnt++;
		for (int j = i; j >= 0; j--)
		{
			if (s[i] == s[j] && i + 1 < n && j -  1 >= 0 &&dp[i + 1][j - 1])
			{
				dp[i][j] = 1;
				cnt++;
			}
		}
	}
	return cnt;
}


bool isPal(string& s)
{
	int left = 0;
	int right = s.size() - 1;
	while (left <= right)
	{
		if (s[left] != s[right])
		{
			return false;
		}
		left++;
		right--;
	}
	return true;
}
//string longestPalindrome(string s)
//{
//	int max_ = 0; 
//	int max_index = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		for (int j = 1; j <= s.size() - i; j++)
//		{
//			if (isPal(s.substr(i, j)))
//			{
//				if (j >= max_)
//				{
//					max_ = j;
//					max_index = i;
//				}
//			}
//		}
//	}
//	return s.substr(max_index, max_);
//}
//




int longestPalindrome(string s) {
	int chars[128] = { 0 };
	for (int i = 0; i < s.size(); i++)
	{
		chars[s[i]]++;
	}

	bool flag = 0;
	int count = 0;
	for (int i = 0; i < 128; i++)
	{
		if (chars[i] % 2 == 0)
		{
			count += chars[i];
		}
		else if (chars[i] % 2 != 0 && chars[i] > 2)
		{
			count += chars[i] - 1;
			flag = 1;
		}
		else if (chars[i] == 1)
		{
			flag = 1;
		}

	}
	if (flag == 1)
		return count + 1;
	else
		return count;
}
int main()
{

	longestPalindrome("abccccdd");
	cout << longestPalindrome("abadc") << endl;
	system("pause");
}