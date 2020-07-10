#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <cmath>
using namespace std;
//class Solution {
//public:
//	int N = 10;
//	int bit[10];
//	
//	int getsum(int n){
//		int ans = 0;
//		while (n){
//			ans += bit[n];
//			n = n&(n - 1);
//		}
//		return ans;
//	}
//	void update(int n, int k){
//		while (n<N){
//			bit[n] += k;
//			n += n&(-n);
//		}
//	}
//	string minInteger(string num, int k) {
//		int n = num.size();
//		memset(bit, 0, sizeof bit);
//		vector<int>cnt(10, 0);
//		vector<vector<int>>pos(10);
//		for (int i = 0; i<num.size(); i++){
//			pos[num[i] - '0'].push_back(i + 1);
//		}
//		string ans;
//		for (int i = 1; i <= n; i++){
//			for (int j = 0; j <= 9; j++){
//				if (cnt[j] >= pos[j].size()) continue;
//				int c = pos[j][cnt[j]] + getsum(pos[j][cnt[j]]) - i;
//				if (c <= k){
//					k -= c;
//					ans.push_back(j + '0');
//					update(1, 1);
//					update(pos[j][cnt[j]], -1);
//					cnt[j]++;
//					break;
//				}
//			}
//		}
//		return ans;
//	}
//};

class Solution {
public:
	int n;
	vector<int> tr;

	int lowbit(int x)
	{
		return x& -x;
	}

	void add(int x, int y)
	{
		for (int i = x; i <= n; i += lowbit(i))
		{
			tr[i] += y;
		}

	}
	int get_sum(int x)
	{
		int res = 0;
		for (int i = x; i; i -= lowbit(i))
			res += tr[i];
		return res;
	}
	string minInteger(string num, int k) {
		n = num.size();
		if (k > num.size() *(num.size() - 1) / 2)
		{
			sort(num.begin(), num.end());
			return num;
		}

		int a = 0;
		char min;
		int j;
		for (int i = 0; i < num.size(); i++)
		{
			min = num[i];
			a = i;
			for (int j = i; j < n && j < i + k + 1; j++)
			{
				if (num[j] < min)
				{
					min = num[j];
					a = j;
				}
			}
			for (int t = a; t > i; t--)
			{
				if (k > 0)
				{
					char c = num[t];
					num[t] = num[t - 1];
					num[t - 1] = c;
					k--;
				}
				else
					return num;
			}
		}
		return num;
	}
};

int main()
{
	Solution s;
	string nums = "4321";
	int k = 4;
	cout << s.minInteger(nums, k) << endl;
	system("pause");
}