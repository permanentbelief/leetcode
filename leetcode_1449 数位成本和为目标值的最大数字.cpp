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

#include <map>
class Solution {
public:
	string largestNumber(vector<int>& cost, int target) {
		vector<vector<int>> f(10, vector<int>(target + 1));

		for (int i = 1; i <= target; i++) f[0][i] = -1e8;
		for (int i = 1; i <= 9; i++)
		for (int j = 0; j <= target; j++)
		{
			f[i][j] = f[i - 1][j];
			if (j >= cost[i - 1]) f[i][j] = max(f[i][j], f[i][j - cost[i - 1]] + 1);
		}

		if (f[9][target] < 1) return "0";
		string res;

		for (int i = 9, j = target; i; i--)
		while (j >= cost[i - 1] && f[i][j] == f[i][j - cost[i - 1]] + 1)
		{
			res += to_string(i);
			j -= cost[i - 1];
		}

		return res;
	}
};

int main()
{
	Solution s;
	string str = "0110";
	int k = 2;

	//vector<int> v = { { 978196917, 202623379, 552387129, 754071585, 366121947, 444381377, 774799689, 300436332, 851324710, 360072179 }
	//	 };
	//int k = 6;
	//
	//s.findLeastNumOfUniqueInts(v, k);
	//int k = 10;
	

	vector<vector<int>> e = { { 3, 4 }, { 2, 3 }, { 1, 2 } };
	// { { 2, 100 }, { 3, 200 }, { 4, 300 }, { 5, 500 }, { 5, 400 }, { 5, 250 }, { 6, 370 }, { 6, 360 }, { 7, 380 } };
	//s.findRightInterval(e);

		
	//vector<int> endTimes = { 3, 5, 5, 6 };
	//vector<int> profit = { 50, 10, 40, 70 };
	
	/*s.jobScheduling(s1, endTimes, profit);*/
	system("pause");
}