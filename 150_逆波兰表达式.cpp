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
	int evalRPN(vector<string> tokens) {
		if (tokens.empty())
			return 0;
		stack<int> ss;
		double num1 = 0;
		double num2 = 0;
		double c = 0;
		for (int i = 0; i < tokens.size(); i++)
		{
			if (!ss.empty() && tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
			{
				if (tokens[i] == "+")
				{
					num1 = ss.top();
					ss.pop();
					num2 = ss.top();
					c = num1 + num2;
				}
				else if (tokens[i] == "-")
				{
					num1 = ss.top();
					ss.pop();
					num2 = ss.top();
					c = num2 - num1;
				}
				else if (tokens[i] == "*")
				{
					num1 = ss.top();
					ss.pop();
					num2 = ss.top();
					c = num1*num2;
				}
				else
				{
					num1 = ss.top();
					ss.pop();
					num2 = ss.top();
					c = num2 / num1;
				}
				ss.pop();
				ss.push(c);

			}
			else if (tokens[i] != "+" || tokens[i] != "-" || tokens[i] != "*" || tokens[i] != "/")
			{
				ss.push(stoi(tokens[i]));
			}

		}
		return ss.top();
	}
};
int main()
{
	Solution s;
	cout << s.evalRPN({ "2", "1", "+", "3", "*" }) << endl;

	system("pause");
}