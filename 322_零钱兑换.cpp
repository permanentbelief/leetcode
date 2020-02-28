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
	/*void DFS(vector<int>& coins, vector<int> tmp, int amount, double cur, int& min)
	{
		if (cur >= amount)
		{
			if (amount == cur)
			{
				if (tmp.size() < min)
				{
					min = tmp.size();
				}
			}
			return;
		}
		for (int i = 0; i < coins.size(); i++)
		{
			tmp.push_back(coins[i]);
			DFS(coins, tmp, amount, cur + coins[i], min);
			tmp.pop_back();
		}
	}
	int coinChange(vector<int> coins, int amount) {
		vector<int> tmp;
		int min = INT_MAX;
		DFS(coins, tmp, amount, 0.0, min);
		if (min == INT_MAX)
			return -1;
		else
			return min;
	}*/
	int coinChange(vector<int> coins, int amount) {
		if (amount == 0) return 0;
		int ans = INT_MAX;
		for (int coin : coins) {
			// 金额不可达
			if (amount - coin < 0) continue;
			int subProb = coinChange(coins, amount - coin);
			// 子问题无解
			if (subProb == -1) continue;
			ans = min(ans, subProb + 1);
		}
		return ans == INT_MAX ? -1 : ans;
	}
};
int main()
{
	Solution s;
	cout << s.coinChange({ 1, 3}, 3) << endl;
	system("pause");
}
