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
	int max_ = 0;
	void dfs(vector<vector<int>>& grid, int m, int n, int x, int y, int& res)
	{
		static int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
		//res++;
		cout << "x : " << x << " " << "y : " << y << endl;
		max_ = max(max_, res);
		int val = grid[x][y];
		grid[x][y] = -1;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + pos[i][0];
			int ny = y + pos[i][1];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n ||
				grid[nx][ny] != 1 || grid[nx][ny] == -1)
				continue;
			//res += 1;
			dfs(grid, m, n, nx, ny, res += 1);

		}
		grid[x][y] = val;
	}
	int largestIsland(vector<vector<int>>& grid) {
		//   1 1 1 0 1
		//   0 1 0 1 0
		//   
		//
		//
		//
		if (grid.empty())
			return 0;
		int m = grid.size();
		int n = grid[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 0)
				{
					int val = 1;
					dfs(grid, m, n, i, j, val);
				}
			}
		}
		return max_;
	}
};

int main()
{
	Solution s;
	vector<vector<int>>  vv = { { 1, 1 }, { 1, 0 } };

	s.largestIsland(vv);
	
	system("pause");
}