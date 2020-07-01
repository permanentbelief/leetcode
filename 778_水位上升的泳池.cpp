#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
using namespace std;


class Solution1 {
public:

	
	//struct cmp
	//{
	//	bool operator()(int k1, int k2)
	//	{
	//		return grid[k1 / N][k1%N] < grid[k2 / N][k2%N];  //这里定义表达式，找不到数组
	//	}

	//};
	int swimInWater(vector<vector<int>>& grid) {


		int N = grid.size();
		set<int> seen;
		priority_queue<int, vector<int>, [](int k1, int k2)
		{
			return grid[k1 / N][k1%N] < grid[k2 / N][k2%N]; //定义比较器这里有问题,lambda表达式不知道哪错了
		}> pq;

		pq.push(0);
		int ans = 0;

		 vector<int> dr{1, -1, 0, 0};
		 vector<int> dc{ 0, 0, 1, -1 };

		while (!pq.empty()) {
			int k = pq.top();
			pq.pop();
			int r = k / N, c = k % N;
			ans = max(ans, grid[r][c]);
			if (r == N - 1 && c == N - 1) return ans;

			for (int i = 0; i < 4; ++i) {
				int cr = r + dr[i], cc = c + dc[i];
				int ck = cr * N + cc;
				if (0 <= cr && cr < N && 0 <= cc && cc < N && !seen.count(ck)) {
					pq.push(ck);
					seen.insert(ck);
				}
			}
		}

		return 0;
	}

};
int main()
{
	Solution1 s;
	s.swimInWater({ { 0, 1 } });
	system("pause");
}