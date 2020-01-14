#define _CRT_SECURE_NO_WARNINGS 1 


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
	//方法一 带有返回值的DFS
	//int DFS(vector<vector<int>>& grid, int x, int y)
	//{
	//	if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0)
	//		return 0;
	//	grid[x][y] = 0;
	//	return 1+ DFS(grid, x + 1, y)
	//	+ DFS(grid, x - 1, y )
	//	+ DFS(grid, x, y - 1)
	//	+ DFS(grid, x, y + 1);
	//}
	//方法二
	void DFS(vector<vector<int>>& grid, int x, int y, int& area)
	{
		static int pos[4][2] = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };
		grid[x][y] = 0;
		area += 1;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + pos[i][0];
			int ny = y + pos[i][1];
			if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] == 0)
				continue;
			if (grid[nx][ny] == 1)
				DFS(grid, nx, ny, area);
		}
	}
	int maxAreaOfIsland(vector<vector<int>> grid) {
		if (grid.empty())
			return 0;
		int maxnum = 0;
		int area = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == 1)
				{
				
					DFS(grid, i, j, area);
				}
				if (area > maxnum)
				{
					maxnum = area;
					area = 0;
				}
					
			}
		}
		return maxnum;

	}
};
int main()
{
	Solution s;
	cout << s.maxAreaOfIsland({ { 1, 1, 0, 1, 1 },
								{ 1, 0, 0, 0, 0 }, 
								{ 0, 0, 0, 0, 1 },
								{ 1, 1, 0, 1, 1 } }) << endl;
	system("pause");
}