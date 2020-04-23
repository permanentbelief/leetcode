#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

int changed(int amount, vector<int> coins)
{
	int n = coins.size();
	vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;
	for (int j = 1; j <= amount; j++)
	{
		dp[0][j] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= amount; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j - coins[i - 1] >= 0)
				dp[i][j] += dp[i][j - coins[i-1]];
		}
	}

	return dp[n][amount];

}
int changed1(int amount, vector<int> coins)
{
	int n = coins.size();
	vector<int> dp(amount + 1);
	dp[0] = 1;
	//错误写法
	//for (int i = 1; i <= amount; i++) {
	//	for (int coin : coins) {
	//		if (i - coin < 0) break;
	//		dp[i] = (dp[i] + dp[i - coin]) % 1000000007;
	//	}
	//}

	//return dp[amount];


	for (int i = 0; i < n; i++)
	{
		for (int j = coins[i]; j <= amount; j++)
		{
			dp[j] = dp[j] + dp[j - coins[i]];
		}
	}
	return dp[amount];
}
void dfs(int sum, int& count, int n, vector<int>& pos, int start)
{
	
	if (sum == n)
	{
		count++;
		return;
	}
	for (int i = start; i < 4; i++)
	{
		if (sum + pos[i] <= n)
		{
			sum += pos[i];
			dfs(sum, count, n, pos,i);
			sum -= pos[i];
		}
	
	}
}
int waysToChange1(int n) {
	int count = 0;
	vector<int> pos = { 1, 5, 10, 25 };
	dfs(0, count, n, pos,0);
	return count;

}
void help(int coins[4], int n, long long &sum, int val, int start)
{
	if (val == n)
	{
		sum = (sum + 1) % 1000000007;
		return;
	}
	for (int i = start; i<4; i++)
	{
		if (val + coins[i] <= n){
			val += coins[i];
			help(coins, n, sum, val, i);
			val -= coins[i];
		}
	}
}
int waysToChange(int n) {
	int coins[4] = { 1, 5, 10, 25 };
	long long sum = 0;
	help(coins, n, sum, 0, 0);
	return sum;
}
// int main()
//{
//	vector<int> v = { 1, 5, 10, 20 };
//	int  amount = 6;
//	cout << changed(amount, v) << endl;
//	//Solution s; 
//	//cout << waysToChange1(10) << endl;
//	//cout << waysToChange(10) << endl;
//	system("pause");
//
//
//}
//int numberOfSubarrays(vector<int>& nums, int k) {
//	// 奇数为1, 偶数为0, 子区间和为k的种类数
//	int len = nums.size();
//	for (int i = 0; i<len; i++) {
//		if (nums[i] & 1) nums[i] = 1;
//		else nums[i] = 0;
//	}
//
//	unordered_map<long long, int> mp;
//	long long sum = 0;
//	mp[0] = 1;
//	int res = 0;
//	for (int i = 1; i <= len; i++) {
//		sum += nums[i - 1];
//		// sum - k = x
//		res += mp[sum - k];
//		mp[sum] ++;
//	}
//	return res;
//}
//

#include <map>
int subarraySum(vector<int>& nums, int k)
{
	int count = 0;
	int sum = 0;
	map<int, int> mymap;
	mymap[0] = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
		if (mymap.find(sum - k) != mymap.end())
		{
			count += mymap[sum - k];
		}
		mymap[sum]++;
	}
	return count;
}

//滑动窗口
//1. 不断右移right来扩大滑动窗口 使其包含k个奇数
//int subarraySum(vector<int>& nums, int k)
//{
//	int left = 0;
//	int right = 0;
//	int oddCnt = 0;
//	int res = 0;
//	while (right < nums.size())
//	{
//		if ((nums[right++] & 1) == 1)
//		{
//			oddCnt++;
//		}
//
//		//若当前滑动窗口[left,right)中有k个奇数了，
//		//先将滑动窗口的右边界向右拓展,直到遇到下一个奇数
//		int tmp = right;
//		while (right < nums.size() && (nums[right] & 1) == 0)
//		{
//			right++;
//		}
//		int rightEvenCnt = right - tmp;
//		int leftEvenCnt = 0;
//		while ((nums[left] & 1) == 0)
//		{
//			leftEvenCnt++;
//			left++;
//		}
//		res += (leftEvenCnt + 1)*(rightEvenCnt + 1);
//
//		left++;
//		oddCnt--;
//
//
//	}
//}
//


//int main()
//{
//
//	system("pause");
//}