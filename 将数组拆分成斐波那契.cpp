#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
class Solution
{
public:
	bool backtrack(string& S, int i, int j, int k, vector<int>& res)
	{
		if (S[i] == '0' && j - i > 1 || (S[j] == '0' && k - j > 1)) //相差一位的话满足题意
			return false;
		long long a = 0;
		long long b = 0;
		for (int c = i; c < j; c++)
		{
			a = a * 10 + S[c] - '0';
			if (a > INT_MAX)
				return false;
		}
		for (int c = j; c < k; c++)
		{
			b = b * 10 + S[c] - '0';
			if (b > INT_MAX)
				return false;
		}
		if (k == S.size())
		{
			res.push_back(a);
			res.push_back(b);
			return true;
		}

		string nums = to_string(a + b);
		for (int c = 0; c < nums.size(); c++)
		{
			if (S[c + k] != nums[c])
				return false;
		}
		res.push_back(a);
		return backtrack(S, j, k, k + nums.size(), res);
	}
	vector<int> splitIntoFibonacci(string& S)
	{
		vector<int> res;
		int i = 0;
		for (int j = i + 1; j < S.size(); j++)
		{
			for (int k = j + 1; k < S.size(); k++)
			{
				res.clear();
				if (backtrack(S, i, j, k, res))
				{
					if (res.size() > 2)
						return res;
				}
			}
		}
		return res;
	}
};


class Solution1 {
public:
	void dfs(vector<vector<int>>& grid, vector<vector<bool>>& books, int x, int y, int& max_, int sum)
	{
		if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || books[x][y] == 1)
		{
			return;
		}
		sum += grid[x][y];
		max_ = max(sum, max_);
		//cout << "[" << x << "," << y << "]" << endl;
		books[x][y] = 1;
		static int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
		for (int i = 0; i < 4; i++)
		{
			int nx = x + pos[i][0];
			int ny = y + pos[i][1];
			if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && books[nx][ny] == 0 && grid[nx][ny] != 0
				&& grid[x][y] != 0)
			{
				dfs(grid, books, nx, ny, max_, sum);
				books[nx][ny] = 0;
			}

		}
		sum -= grid[x][y];
		books[x][y] = 0;
	}
	int getMaximumGold(vector<vector<int>>& grid) {
		if (grid.empty())
			return 0;
		int max_ = 0;
		vector<vector<bool>> books(grid.size(), vector<bool>(grid[0].size()));
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] != 0)
				{
					dfs(grid, books, i, j, max_, 0);
				}
			}
		}
		return max_;
	}
};
//int main()
//{
//	
//	/*Solution s;
//	string str = "123";
//	s.splitIntoFibonacci(str);*/
//	Solution1 s;
//	vector<vector<int>> v = { {0,6,0}, {5,8,7}, {0,9,0} };
//	cout << s.getMaximumGold(v) << endl;
//	system("pause");
//}