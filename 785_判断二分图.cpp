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
//		// ���� visited ���飬��ʼֵΪ 0 ��ʾδ�����ʣ���ֵΪ 1 ���� -1 ��ʾ���ֲ�ͬ����ɫ�� 
//		vector<int> visited(n, 0);
//		queue<int> q ;
//		// ��Ϊͼ�п��ܺ��ж����ͨ������������Ҫ�ж��Ƿ���ڶ���δ�����ʣ��������������ʼ�ٽ���һ�� bfs Ⱦɫ��
//		for (int i = 0; i < graph.size(); i++) {
//			if (visited[i] != 0) {
//				continue;
//			}
//			// ÿ����һ�����㣬���������ڽӵ�Ⱦ���෴����ɫ����ӡ�
//			q.push(i);
//			visited[i] = 1;
//			while (!q.empty()) {
//				int v = q.front();
//				q.pop();
//				for (auto e : graph[v]) {
//					// �����ǰ�����ĳ���ڽӵ��Ѿ���Ⱦ��ɫ�ˣ�����ɫ�͵�ǰ������ͬ��˵��������ͼ�޷�����ȷȾɫ������ false��
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
