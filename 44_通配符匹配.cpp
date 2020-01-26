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
	bool isMatch(string s, string p) {
		int row = s.size();
		int col = p.size();
		vector<vector<bool>> book(row + 1, vector<bool>(col + 1, false));
		book[0][0] = true;
		for (int i = 1; i <= col; i++)
		{
			if (p[i-1] == '*')
				book[0][i] = book[0][i-1]; // 就相当于true
		}
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (book[i - 1][j - 1] && (s[i-1] == p[j-1] || p[j-1] == '?'))
					book[i][j] = true;
				if (p[j-1] == '*')
					book[i][j] = (book[i][j - 1] || book[i - 1][j]);
			}
		}
		return book[row][col];
	}

};
int main()
{
	Solution s;
	string a = "aa";
	string b = "*";
	cout << s.isMatch(a, b) << endl;
	system("pause");
}