#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
	string add(string& num1, string& num2)
	{
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		int n1 = num1.size();
		int n2 = num2.size();

		string tmp;
		tmp.resize(max(n1, n2));
		int index = 0;
		int next = 0;

		int i = 0;
		int j = 0;

		while (i < n1 || j < n2)
		{
			int Sum = 0;
			Sum += (i < n1 ? num1[i++] - '0' : 0);
			Sum += (j < n2 ? num2[j++] - '0' : 0);
			Sum += next;
			next = 0;
			if (Sum > 9)
			{
				next = 1;
				Sum -= 10;
			}
			tmp[index++] = Sum + '0';
		}
		if (next == 1)
		{
			tmp.push_back('1');
		}
		reverse(tmp.begin(), tmp.end());
		return tmp;
	}
	bool dfs(string& s, int i , int j, int k)
	{
		if ((s[i] == '0' && j - i > 1) || (s[j] == '0' && k - j > 1))
			return false;
		string a = s.substr(i, j - i);
		string b = s.substr(j, k - j);
		string num = add(a, b);
		int n = num.size();
		if (k + n > s.size() || num != s.substr(k, n))
			return false;
		if (k + n == s.size())
			return true;
		return dfs(s, j, k, k + n);

	}
	bool isAdditiveNumber(string num)
	{
		int i = 0;
		for (int j = i + 1; j < num.size(); j++)
		{
			for (int k = j + 1; k < num.size(); k++)
			{
				if (dfs(num, i, j, k))
					return true;
			}
		}
	}
	
};

string add(string& num1, string& num2)
{
	int n1 = num1.size() - 1;
	int n2 = num2.size() - 1;
	int carry = 0;
	string ans;
	while (n1 >= 0 || n2 >= 0 || carry > 0)
	{
		int t1 = n1 >= 0 ? num1[n1--] - '0' : 0;
		int t2 = n2 >= 0 ? num2[n2--] - '0' : 0;
		ans += (t1 + t2 + carry) % 10 + '0';
		carry = (t1 + t2 + carry) >= 10 ? 1 : 0;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}


void dfs(vector<string>& vs, string S, int cur)
{
	if (S.size() == cur)
	{
		vs.push_back(S);
		return;
	}
	for (int i = cur; i < S.size(); i++)
	{
		swap(S[cur], S[i]);
		dfs(vs, S, cur + 1);
		swap(S[cur], S[i]);

	}
}
vector<string> permutation(string S) {
	vector<string> vs;
	dfs(vs, S, 0);
	return vs;
}
//int main()
//{
//	string S = "aab";
//	permutation(S);
//	system("pause");
//}