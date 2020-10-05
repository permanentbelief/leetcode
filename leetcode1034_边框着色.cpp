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

	vector<vector<int>> vv;
	vector<vector<bool>> vvb;
	void dfs(vector<vector<int>>& grid, int x, int y, int m, int n, int color, int oldcolor)
	{
		static int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
		int res = 0;
		vvb[x][y] = true;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + pos[i][0];
			int ny = y + pos[i][1];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n
				|| grid[nx][ny] != oldcolor || vvb[nx][ny] == true)
				continue;
			res++;
			dfs(grid, nx, ny, m, n, color, oldcolor);

		}
		if (res < 4)
			grid[x][y] = color;

	}
	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
		vv = grid;
		if (grid.empty())
			return vv;
		int m = grid.size();
		int n = grid[0].size();
		vvb = vector<vector<bool>>(m, vector<bool>(n, false));
		int oldcolor = grid[r0][c0];
		dfs(grid, r0, c0, m, n, color, oldcolor);
		return grid;
	}
};
int main()
{
	Solution s;
	vector<vector<int>> vv = { { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 } };
	s.colorBorder(vv, 1, 1, 2);
	system("pause");
}