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
//
//vector<pair<int, int>> normalize(vector<pair<int, int>> &a) {
//	vector<vector<pair<int, int>>> ret(8, vector<pair<int, int>>());
//	for (auto &p : a) {
//		int x = p.first, y = p.second;
//		ret[0].push_back(make_pair(x, y));
//		ret[1].push_back(make_pair(x, -y));
//		ret[2].push_back(make_pair(-x, y));
//		ret[3].push_back(make_pair(-x, -y));
//		ret[4].push_back(make_pair(y, x));
//		ret[5].push_back(make_pair(y, -x));
//		ret[6].push_back(make_pair(-y, x));
//		ret[7].push_back(make_pair(-y, -x));
//	}
//	for (int i = 0; i < 8; ++i) {
//		sort(ret[i].begin(), ret[i].end());
//		int r_offset = 0 - ret[i][0].first, c_offset = 0 - ret[i][0].second;
//		for (int j = 0; j < ret[i].size(); ++j) {
//			ret[i][j].first += r_offset;
//			ret[i][j].second += c_offset;
//		}
//	}
//	sort(ret.begin(), ret.end());
//	return ret[0];
//}
//
//class Solution {
//public:
//
//	int max_ = 0;
//	void dfs(vector<vector<int>>& matrix, int m, int n, int x, int y, int res)
//	{
//		static int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
//		int val = matrix[x][y];
//
//		cout << "x: " << x << ", y: " << y << "res : " << res << endl;
//		max_ = max(max_, res);
//
//		matrix[x][y] = -1;
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = x + pos[i][0];
//			int ny = y + pos[i][1];
//			if (nx < 0 || ny < 0 || nx >= m || ny >= n || matrix[nx][ny] <= matrix[x][y]
//				|| matrix[nx][ny] == -1)
//				continue;
//			dfs(matrix, m, n, nx, ny, res + 1);
//
//		}
//		matrix[x][y] = val;
//
//	}
//	int longestIncreasingPath(vector<vector<int>>& matrix) {
//		if (matrix.empty())
//			return 0;
//		int m = matrix.size();
//		int n = matrix[0].size();
//		for (int i = 0; i < m; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				dfs(matrix, m, n, i, j, 0);
//			}
//		}
//		return max_ + 1;
//	}
//
//};
//int main()
//{
//	// vector<pair<int, int>> a = { { 1, 3 }, { 1, 2 }, { 1, 4 } };
//	// normalize(a);
//
//	vector<vector<int>> vv = { { 9, 9, 4 }, { 6, 6, 8 }, { 2, 1, 1 } };
//	Solution s;
//	s.longestIncreasingPath(vv);
//	
//	system("pause");
//}