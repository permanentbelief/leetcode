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
	int smallestDistancePair(vector<int>& nums, int k) {
		if (nums.size() == 0)
			return 0;
		sort(nums.begin(), nums.end());

		int l = 0;
		int r = nums[nums.size() - 1] - nums[0];
		//看见n的取值 就知道n^2肯定会超时间复杂度，所以要用nlgn的算法时间做

		while (l < r)
		{
			int mid = (l + r) / 2;

			//枚举看比mid小的有没有超过k天
			int count = 0;
			int pre = 0;
			for (int i = 0; i < nums.size(); i++)
			{
				while (pre <= i && nums[i] - nums[pre] > mid) pre++;
				count += i - pre; //有count个数小于等于mid
			}
			if (count >= k) r = mid;
			else l = mid + 1;
		}
		return l;
	}
};

int main()
{
	
	system("pause");
}