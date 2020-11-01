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
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.empty())
			return 0;

		int dif = INT_MAX;
		int sums = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < (int)nums.size() - 2; i++)
		{
			int l = i + 1;
			int r = nums.size() - 1;
			while (l < r)
			{
				if (nums[l] + nums[r] + nums[i] == target)
				{
					return target;
				}
				else if (nums[l] + nums[r] + nums[i] > target)
				{
					if (nums[l] + nums[r] + nums[i] - target < dif)
					{
						dif = nums[l] + nums[r] + nums[i] - target;
						sums = nums[l] + nums[r] + nums[i];
					}
					r--;
				}
				else
				{
					if (abs(nums[l] + nums[r] + nums[i] - target) < dif)
					{
						dif = abs(nums[l] + nums[r] + nums[i] - target);
						sums = nums[l] + nums[r] + nums[i];
					}
					l--;
				}
			}
		}
		return sums;
	}
};
int main()
{
	Solution s;
	vector<int> nums = { -1, 2, 1, -4 };
	int target = 1;
	s.threeSumClosest(nums, target);

	system("pause");
}