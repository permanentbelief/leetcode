#define _CRT_SECURE_NO_WARNINGS 1 


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool BFS(vector<vector<int>>& grid, int sx, int sy, int ex, int ey)
{
	static int pos[4][2] = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };
	int row = grid.size();
	int col = grid[0].size();
	//������

	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));

	// ���
	vector<vector<int>> book(row, vector<int>(col, 0));
	book[sx][sy] = 1;
	//��ʼ����
	while (!q.empty())
	{
		//ȡ��ͷԪ��
		pair<int, int> curPos = q.front();
		q.pop();
		if (curPos.first == ex && curPos.second == ey)
			return true;
		//��������
		for (int i = 0; i < 4; i++)
		{
			int nx = curPos.first + pos[i][0];
			int ny = curPos.second + pos[i][1];

			if (nx < 0 || nx >= row || ny < 0 || ny >= col)
				continue;
			if (grid[nx][ny] == 0 && book[nx][ny] == 0)
			{
				book[nx][ny] = 1;
				q.emplace(nx, ny); //���캯��
			}
		}
		
	}
	return false;

}

int main()
{
	int m = 0;
	int n = 0;
	cin >> m >> n;
	vector<vector<int>> grid(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}
	while (1)
	{
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		cout << BFS(grid, sx, sy, ex, ey) << endl;

	}
	system("pause");
}