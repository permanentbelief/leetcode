#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>


using namespace std;






//class Solution {
//	bool isBipartite(vector<vector<int>>& graph) {
//
//		int n = graph.size();
//		// 定义 visited 数组，初始值为 0 表示未被访问，赋值为 1 或者 -1 表示两种不同的颜色。 
//		vector<int> visited(n, 0);
//		queue<int> q ;
//		// 因为图中可能含有多个连通域，所以我们需要判断是否存在顶点未被访问，若存在则从它开始再进行一轮 bfs 染色。
//		for (int i = 0; i < graph.size(); i++) {
//			if (visited[i] != 0) {
//				continue;
//			}
//			// 每出队一个顶点，将其所有邻接点染成相反的颜色并入队。
//			q.push(i);
//			visited[i] = 1;
//			while (!q.empty()) {
//				int v = q.front();
//				q.pop();
//				for (auto e : graph[v]) {
//					// 如果当前顶点的某个邻接点已经被染过色了，且颜色和当前顶点相同，说明此无向图无法被正确染色，返回 false。
//					if (visited[e] == visited[v]) {
//						return false;
//					}
//					if (visited[e] == 0) {
//						visited[e] = -visited[v];
//						q.push(e);
//					}
//				}
//			}
//		}
//
//		return true;
//	}
//};
//int main()
//{
//	Solution s;
//	vector<vector<int>> v = { { 1, 3 }, { 0, 2 }, { 1, 3 }, { 0, 2 } };
//
//	s.isBipartite(v);
//	system("pause");
//}
