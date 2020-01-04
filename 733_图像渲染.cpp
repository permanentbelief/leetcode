#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void DFS(vector<vector<int>>& image, int x, int y, int newColor, int oldColor)
	{
		static int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
		image[x][y] = newColor;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + pos[i][0];
			int ny = y + pos[i][1];
			if (nx < 0 || nx >= image.size() || ny < 0 || ny >= image[0].size())
				continue;
			if (image[nx][ny] == oldColor)
				DFS(image, nx, ny, newColor, oldColor);
		}
	}
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		if (image.empty())
			return image;
		int oldColor = image[sr][sc];
		 if(oldColor == newColor)
		   return image;
		DFS(image, sr, sc, newColor, oldColor);
		return image;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> image = { { 0, 0, 0 }, { 0, 0, 0 } };
	s.floodFill(image, 0, 0, 0);
	system("pause");
}