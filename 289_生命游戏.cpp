//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
////class Solution {
////public:
////	int Find(vector<vector<int>>&board, int i, int j, int Find_num)
////	{
////		static int pos[][8] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 }, { -1, -1 }, { -1, 1 }, { 1, 1 }, { 1, -1 } };
////		int count = 0;
////		for (int k = 0; k < 8; k++)
////		{
////			int nx = i + pos[k][0];
////			int ny = j + pos[k][1];
////			if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size())
////				continue;
////			if (board[nx][ny] == Find_num)
////			{
////				count++;
////			}
////		}
////		return count;
////	}
////
////	void gameOfLife(vector<vector<int>>& board) {
////		if (board.empty())
////		{
////			return;
////		}
////		vector<vector<int>> vv(board.size(), vector<int>(board[0].size(), 0));
////		for (int i = 0; i < board.size(); i++)
////		{
////			for (int j = 0; j < board[0].size(); j++)
////			{
////				if (board[i][j] == 1 && (Find(board, i, j, 1) == 2 || Find(board, i, j, 1) == 3))
////				{
////					vv[i][j] = 1;
////				}
////				else if (board[i][j] == 0 && (Find(board, i, j, 1) == 3))
////				{
////					vv[i][j] = 1;
////				}
////			}
////		}
////		for (int i = 0; i < board.size(); i++)
////		{
////			for (int j = 0; j < board[0].size(); j++)
////			{
////				board[i][j] = vv[i][j];
////			}
////		}
////	}
////};
//
//
//// 542 01矩阵
//class Solution {
//public:
//
//	void BFS(vector<vector<int>>& board,vector<vector<bool>>& books, int x, int y, int& step)
//	{
//		queue<pair<int, int>> q;
//		
//		q.push(make_pair(x, y));
//		static int pos[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
//		while (!q.empty())
//		{
//			pair<int, int> tmp = q.front();
//			// books[tmp.first][tmp.second] = false;
//			int size = q.size();
//			q.pop();
//			bool flag1 = true;
//			while (size--)
//			{
//				bool flag = false;
//				for (int i = 0; i < 4; i++)
//				{
//					int nx = pos[i][0] + tmp.first;
//					int ny = pos[i][1] + tmp.second;
//					if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size())
//					{
//						continue;
//					}
//					else
//					{
//						if (board[nx][ny] == 0)
//						{
//							flag = true;
//							break;
//						}
//						//if (books[nx][ny])
//						q.push(make_pair(nx, ny));
//					}
//				}
//				if (flag)
//				{
//					flag1 = false;
//					break;
//				}
//			}
//			step += 1;
//			if (flag1 == false)
//				return;
//
//		}
//	}
//	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
//		if (matrix.empty())
//			return matrix;
//		int row = matrix.size();
//		int col = matrix[0].size();
//		vector<vector<bool>> books(row, vector<bool>(col, false));
//		vector<vector<int>> out(row, vector<int>(col, 0));
//		for (int i = 0; i < row; i++)
//		{
//			for (int j = 0; j < col; j++)
//			{
//				if (matrix[i][j] == 0)
//					continue;
//				else
//				{
//					int step = 0;
//					BFS(matrix,books, i, j, step);
//					out[i][j] = step;
//				}
//			}
//		}
//		return out;
//	}
//};
//
////int main()
////{
////	Solution s;
////	vector<vector<int>> board = {
////		{ 1, 1, 1, 1, 0, 1, 0, 0, 1, 1 } };
////	s.updateMatrix(board);
////	system("pause");
////}
//
//
///*
//class Solution {
//
//	public int maxDistance(int[][] grid) {
//		int[] dx = { 0, 0, 1, -1 };
//		int[] dy = { 1, -1, 0, 0 };
//
//		Queue<int[]> queue = new ArrayDeque<>();
//		int m = grid.length, n = grid[0].length;
//		// 先把所有的陆地都入队。
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				if (grid[i][j] == 1) {
//					queue.offer(new int[] {i, j});
//				}
//			}
//		}
//
//		// 从各个陆地开始，一圈一圈的遍历海洋，最后遍历到的海洋就是离陆地最远的海洋。
//		boolean hasOcean = false;
//		int[] point = null;
//		while (!queue.isEmpty()) {
//			point = queue.poll();
//			int x = point[0], y = point[1];
//			// 取出队列的元素，将其四周的海洋入队。
//			for (int i = 0; i < 4; i++) {
//				int newX = x + dx[i];
//				int newY = y + dy[i];
//				if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] != 0) {
//					continue;
//				}
//				grid[newX][newY] = grid[x][y] + 1; // 这里我直接修改了原数组，因此就不需要额外的数组来标志是否访问
//				hasOcean = true;
//				queue.offer(new int[] {newX, newY});
//			}
//		}
//
//		// 没有陆地或者没有海洋，返回-1。
//		if (point == null || !hasOcean) {
//			return -1;
//		}
//
//		// 返回最后一次遍历到的海洋的距离。
//		return grid[point[0]][point[1]] - 1;
//
//	}
//}
//
//*/
//class Solution1
//{
//public:
//	static bool Compare(string& a, string& b)
//	{
//		return a.size() < b.size();
//	}
//
//	int minimumLengthEncoding(vector<string>& words) {
//		if (words.size() == 0)
//			return 0;
//		sort(words.begin(), words.end());
//		words.erase(unique(words.begin(), words.end()), words.end());
//		sort(words.begin(), words.end(), Compare);
//		vector<bool> books(words.size(), false);
//		for (int i = words.size() - 1; i >= 1; i--)
//		{
//			for (int k = i - 1; k >= 0; k--)
//			{
//				for (int j = words[k].size(); j <= words[i].size(); j++)
//				{
//					if (words[i].substr(j - words[k].size(), words[k].size()) == words[k])
//					{
//						books[k] = true;
//					}
//				}
//			}
//			
//		}
//		int cnt = 0;
//		for (int i = 0; i < books.size(); i++)
//		{
//			if (!books[i])
//			{
//				cnt += words[i].size() + 1;
//			}
//		}
//		return cnt;
//	}
//};
//int main()
//{
//	Solution1 s;
//	vector<string> vs = { "time", "me", "bell" };
//	cout << s.minimumLengthEncoding(vs) << endl;
//	system("pause");
//}
//
////#include <unordered_map>
////class Solution {
////public:
////	vector<string> Is_valid(vector<string>&s1, vector<string>& s2)
////	{
////		unordered_map<int, int> Push;
////		for (int i = 1; i < s1.size(); i++)
////		{
////			for (int j = 1; j < s2.size(); j++)
////			{
////				if (s1[i] == s2[j])
////				{
////					Push[j]++;
////				}
////			}
////		}
////		if (Push.empty())
////			return{};
////		else
////		{
////			for (int i = 1; i < s2.size(); i++)
////			{
////				if (Push.find(i) == Push.end())
////				{
////					s1.push_back(s2[i]);
////				}
////			}
////			return s1;
////		}
////	}
////	bool Compare(vector<string>& s1, vector<string>& s2)
////	{
////		return s1[0] < s2[0];
////	}
////	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
////		vector<vector<string>> vvs;
////		if (accounts.empty())
////		{
////			return vvs;
////		}
////		sort(accounts.begin(), accounts.end(), Compare);
////		for (int i = 0; i < accounts.size - 1; i++)
////		{
////
////			if (accounts[i][0] == accounts[i + 1][0])
////			{
////
////				if (Is_valid(accounts[i], accounts[i + 1]) == {})
////					continue;
////			}
////		}
////
////		return vvs;
////	}
////};