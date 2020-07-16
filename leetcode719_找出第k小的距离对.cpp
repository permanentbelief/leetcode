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
		//����n��ȡֵ ��֪��n^2�϶��ᳬʱ�临�Ӷȣ�����Ҫ��nlgn���㷨ʱ����

		while (l < r)
		{
			int mid = (l + r) / 2;

			//ö�ٿ���midС����û�г���k��
			int count = 0;
			int pre = 0;
			for (int i = 0; i < nums.size(); i++)
			{
				while (pre <= i && nums[i] - nums[pre] > mid) pre++;
				count += i - pre; //��count����С�ڵ���mid
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