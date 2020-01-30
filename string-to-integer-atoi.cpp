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
	int atoi(const char *str) {
		long long res = 0;
		if (NULL == str)
		{
			return res;
		}
		int len = strlen(str);
		bool neg = true;
		int i = 0;
		while (str[i] == ' ' || str[i] == '0')
		{
			i++;
		}
		if (str[i] == '-')
		{
			neg = false;
			i++;
		}
		else if (str[i] == '+')
		{
			i++;
		}
		for (; i < len; i++)
		{
			char ch = str[i];
			if (ch >= '0'&&ch <= '9')
			{
				res = res * 10 + ch - '0';
				if (res>INT_MAX)
					return neg ? INT_MAX : INT_MIN;
			}
			else
			{
				return  neg ? res : (-1)*res;
			}
		}
		return neg ? res : (-1)*res;
	}
};
int main()
{
	Solution s;
	cout << s.atoi("200000000000000000") << endl;
	system("pause");
}