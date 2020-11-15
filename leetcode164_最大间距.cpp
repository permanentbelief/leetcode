#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


//class Solution1 {
//public:
//	vector<vector<int>> vv;
//	vector<vector<int>> merge(vector<vector<int>> in) {
//		if (in.empty())
//			return vv;
//
//		sort(in.begin(), in.end());
//		int last = in[0][0];
//		int prev = in[0][1];
//
//
//		for (int k = 1; k < (int)in.size(); k++);
//		{
//				vv.push_back({ last, prev });
//				last = in[k][0];
//				prev = in[k][1];
//			
//		}
//
//		return vv;
//
//	}
//};


class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int max_ = nums[0];
		int min_ = nums[0];

		for (int num : nums)
		{
			max_ = max(max_, num);
			min_ = min(min_, num);
		}

		if (max_ == min_) return 0;
		int n = nums.size();

		vector<int> maxB(n + 1);
		vector<int> minB(n + 1);
		vector<bool> books(n + 1);

		for (auto num : nums)
		{
			int bucket = getBucket(max_, min_, num, n);

			maxB[bucket] = books[bucket] ? max(maxB[bucket], num) : num;
			minB[bucket] = books[bucket] ? min(minB[bucket], num) : num;
			books[bucket] = true;
		}
		int prev = maxB[0];
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			if (books[i])
			{
				res = max(res, minB[i] - prev);
				prev = maxB[i];
			}
		}

		return res;

	}
	int getBucket(long max_, long min_, long num, long n)
	{
		return (int)(num - min_)*n / (max_ - min_);
	}
};

int main()
{
	//Solution s;
	//vector<int> v = { 1,7,9};
	//s.maximumGap(v);


	vector<vector<int>> vv = { { 3, 5 }, { 3, 4 }, { 5, 6 } };
	sort(vv.begin(), vv.end());
	for (int i = 0; i < vv.size(); i++)
	{
		cout << vv[i][0] << " " << vv[i][1] << endl;
	}
	//Solution1 s1;

	system("pause");
}