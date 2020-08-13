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


	//7 22 二刷 但是没有思路  猿辅导
	//状压 dp做法

	int shortestPathLength(vector<vector<int>>& graph) {
		int n = graph.size();
		int dest = (1 << n) - 1;
		vector<vector<bool>>visited(n, vector<bool>(1 << n));

		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++)
		{
			q.push({ i, 1 << i });
			visited[i][1 << i] = true;
		}

		int res = -1;
		while (!q.empty())
		{
			res++;
			int sz = q.size();
			while (sz--)
			{
				auto  cur = q.front();
				q.pop();
				if (cur.second == dest)
					return res;
				for (int next : graph[cur.first])
				{
					int nextState = cur.second | (1 << next);
					if (visited[next][nextState]) continue;
					q.push({ next, nextState });
					visited[next][nextState] = true;
				}
			}
		}
		return res;

	}
};

int main()
{
	
	system("pause");
}