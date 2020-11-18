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
		if (s.empty())
			return 0;
		int sign = 1;
		if (s[0] == '-')
			sign = -1;
		stack<int> ss;

		// int nums = 0 ;
		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int nums = 0;
			//if(ss[i])
			while (i < s.size() && s[i] >= '0' && s[i] <= '9')
			{
				nums = 1ll * nums * 10 + s[i] - '0';
				//cout << nums << endl;
				i++;
			}
			res = res + sign * nums;
			//cout << res << endl;
			if (s[i] == '+')
			{
				sign = 1;
			}
			else if (s[i] == '-')
			{
				sign = -1;
			}
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
	s.calculate("(1+(4+5+2)-3)+(6+8)");

	system("pause");
}