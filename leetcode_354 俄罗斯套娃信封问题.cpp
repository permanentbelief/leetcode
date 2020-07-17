#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
//class Solution {
//public:
//	static bool cmp(pair<int, int>& a, pair<int, int>& b)
//	{
//		if (a.first == b.first)
//		{
//			return a.second > b.second;
//		}
//		return a.first < b.first;
//
//	}
//	int maxEnvelopes(vector<vector<int>>& envelopes) {
//		if (envelopes.empty())
//			return 0;
//		vector<pair<int, int>> vp(envelopes.size());
//		for (int i = 0; i < envelopes.size(); i++)
//		{
//			vp[i] = pair<int, int>(envelopes[i][0], envelopes[i][1]);
//		}
//
//		sort(vp.begin(), vp.end(), cmp);
//
//		vector<int> v;
//		v.push_back(vp[0].second);
//		//bool flag = false;
//		for (int i = 1; i < vp.size(); i++)
//		{
//			//if (flag == false && vp[i - 1].first == vp[i].first)
//			//	continue;
//			if (vp[i].second > v.back())
//			{
//				v.push_back(vp[i].second);
//			}
//			else
//			{
//				/*flag = true;
//				continue;*/
//				int it = lower_bound(v.begin(), v.end(), vp[i].second) - v.begin();
//				v[it] = vp[i].second;
//			}
//			//flag = false;
//		}
//		return v.size();
//	}
//};

class Solution {
public:
	int Max(int a, int b)
	{
		return a > b ? a : b;
	}

	bool CanReach(vector<vector<int>>& grid, vector<vector<int>>& visit, int i, int j, int n)
	{
		int len = grid.size() - 1;
		if (grid[len][len] > n || grid[i][j] > n || visit[i][j] == 1) {
			visit[i][j] = 1;
			return false;
		}
		if (i == j && i == grid.size() - 1) {
			return true;
		}
		visit[i][j] = 1;
		if (i - 1 >= 0 && CanReach(grid, visit, i - 1, j, n)) {
			return true;
		}
		else if (i + 1 < grid.size() && CanReach(grid, visit, i + 1, j, n)) {
			return true;
		}
		else if (j - 1 >= 0 && CanReach(grid, visit, i, j - 1, n)) {
			return true;
		}
		else if (j + 1 < grid.size() && CanReach(grid, visit, i, j + 1, n)) {
			return true;
		}
		return false;
	}

	int swimInWater(vector<vector<int>>& grid) {
		int max = grid[0][0];
		vector<int> arr;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid.size(); j++) {
				arr.push_back(grid[i][j]);
			}
		}
		sort(arr.begin(), arr.end());
		int left = 0;
		int right = arr.size() - 1;
		int ans = arr[right];

		while (left <= right) {
			int mid = (left + right) / 2;
			vector<vector<int>> visit;
			for (int i = 0; i < grid.size(); i++) {
				vector<int> newVec;
				for (int j = 0; j < grid.size(); j++) {
					newVec.push_back(0);
				}
				visit.push_back(newVec);
			}
			if (CanReach(grid, visit, 0, 0, arr[mid])) {
				ans = mid;
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return ans;
	}
};
int main()
{
	Solution s;
	vector<int> v = { 4, 9, 3 };
	int k = 10;
	

	/*vector<vector<int>> e = { { 2, 100 }, { 3, 200 }, { 4, 300 }, { 5, 500 }, { 5, 400 }, { 5, 250 }, { 6, 370 }, { 6, 360 }, { 7, 380 } };
	cout << s.maxEnvelopes(e) <<endl;*/

		
	//vector<int> endTimes = { 3, 5, 5, 6 };
	//vector<int> profit = { 50, 10, 40, 70 };
	
	/*s.jobScheduling(s1, endTimes, profit);*/
	system("pause");
}