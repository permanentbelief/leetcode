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
	void DFS(vector<string>& vs, vector<vector<char>>& board, vector<vector<bool>>& books,
		int size, int x, int y, string str, int row, int col)
	{
		if (size == str.size())
		{
			vs.push_back(str);
			return;
		}
		books[x][y] = true;
		static int pos[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
		for (int i = 0; i < 4; i++)
		{
			int nx = x + pos[i][0];
			int ny = y + pos[i][1];
			if (nx < 0 || nx >= row || ny < 0 || ny >= col || books[nx][ny] == true)
			{
				continue;
			}
			DFS(vs, board, books, size, nx, ny, str += board[nx][ny], row, col);
			
			str.pop_back();
			board[nx][ny] = false;
		}
	}
	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty())
			return true;
		if (board.empty())
			return false;
		int size = word.size();
		vector<string> vs;
		//string str;
		int row = board.size();
		int col = board[0].size();
		vector<vector<bool>> books(row, vector<bool>(col, false));
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				string str;
				DFS(vs, board, books, size, i, j, str += board[i][j], row, col);
			}
		}
		for (int i = 0; i < vs.size(); i++)
		{
			if (vs[i] == word)
				return true;
		}


		return false;
	}
};
int main()
{
	Solution s;
	vector<vector<char>> vvc = { { 'A', 'B' }, { 'S', 'F' } };//, { 'A', 'D', 'E', 'E' } };
	string word = "ABC";
	cout << s.exist(vvc, word) << endl;
	system("pause");
}