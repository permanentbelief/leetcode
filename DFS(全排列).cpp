#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <vector>
using namespace std;
/*
深度优先算法
每一步需要做什么？
1. 到没到边界  边界
2. 处理这件事 这一步做什么？
3. DFS(下一步)
*/


void DFS(int curIdx, vector<int>&box, vector<int>&used, int n)
{
	//边界
	if (curIdx == n)
	{
		for (auto&e : box)
			cout << e << " ";
		cout << endl;
		return;
	}
	//处理当下
	//尝试每一张可用的牌
	for (int i = 1; i <= n; i++)
	{
		if (used[i] == 0)
		{
			box[curIdx] = i;
			used[i] = 1;
			//处理下一个盒子
			DFS(curIdx + 1, box, used, n);
			//回收当前盒子的牌
			used[i] = 0;
		}
	}
}


int main()
{
	int n = 3;
	//cin >> n;
	vector<int> used(n + 1, 0);
	vector<int>box(n, 0);
	DFS(0, box, used, n);
	system("pause");
	return 0;
}
