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
	int calculate(string s) {

		stack<int> ss;
		int res = 0;
		int sign = 1; // Õý¸º
		for (int i = 0; i < s.size(); i++)
		{
			char ch = s[i];
			if (isdigit(ch))
			{
				int cur = ch - '0';
				while (i + 1 < s.size() && isdigit(s[i + 1]))
				{
					cur = cur * 10 + (s[++i] - '0');
				}
				res = res + sign * cur;
			}
			else if (s[i] == '+')
				sign = 1;
			else if (s[i] == '-')
				sign = -1;
			else if (s[i] == '(')
			{
				ss.push(res);
				res = 0;
				ss.push(sign);
				sign = 1;
			}
			else if (s[i] == ')')
			{
				int newsign = ss.top();
				ss.pop();

				int newval = ss.top();
				ss.pop();
				res = newsign * res + newval;
			}
		}
		return res;

	}
};

int main()
{
	Solution s;
	string str = "(1+(4+5+2)-3)";
	s.calculate(str);
	system("pause");
}