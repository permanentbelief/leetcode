#define _CRT_SECURE_NO_WARNINGS 1 


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		if (grid.empty())
			return 0;
		int sum = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == 1)
				{
					sum += 4;
					if (i - 1 >= 0 && grid[i - 1][j] == 1) sum -= 1;
					if (i + 1 < grid.size() && grid[i + 1][j] == 1) sum -= 1;
					if (j + 1 < grid[0].size() && grid[i][j + 1] == 1) sum -= 1;
					if (j - 1 >= 0 && grid[i][j - 1] == 1) sum -= 1;
				}
				
			}
		}
		return sum;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> grid = { { 0, 1, 0, 0 }, { 1, 1, 1, 0 }, { 0, 1, 0, 0 }
	, { 1, 1, 0, 0 } };
	cout << s.islandPerimeter(grid) << endl;
	system("pause");

}
