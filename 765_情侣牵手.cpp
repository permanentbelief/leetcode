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
	vector<int> parent, size;

	int findroot(int x)
	{
		if (x != parent[x]) {
			parent[x] = findroot(parent[x]);
		}
		return parent[x];
	}

	void uni(int x, int y)
	{
		int xroot = findroot(x);
		int yroot = findroot(y);
		if (xroot != yroot) {
			if (size[xroot] < size[yroot]) {
				parent[xroot] = yroot;
				size[yroot] += size[xroot];
			}
			else {
				parent[yroot] = xroot;
				size[xroot] += size[yroot];
			}
		}
	}

	int minSwapsCouples(vector<int> &row)
	{
		int N = row.size() / 2; // 2是数字
		int N2 = row.size();
		parent = vector<int>(N, 0);
		size = vector<int>(N, 1);
		for (int i = 0; i < N; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < N2; i += 2) {    // 2是数字
			uni(row[i] / 2, row[i + 1] / 2);  // 2是数字
		}

		int circle = 0;
		for (int i = 0; i < N; i++) {
			if (i != findroot(i)) {
				circle++;
			}
		}
		return circle;
	}
};
int main()
{
	vector<int> row = { 0, 3, 1, 2 };
	Solution s;
	cout << s.minSwapsCouples(row) << endl;
	system("pause");
}