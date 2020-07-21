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

	vector<int> nums;
	void merge(vector<int>&nums1, vector<int>& nums2)
	{
		int i = 0;
		int j = 0;
		nums.resize(nums1.size() + nums2.size());
		int index = 0;
		while (i < nums1.size() && j < nums2.size())
		{
			if (nums1[i] < nums2[j])
			{
				nums[index++] = nums1[i];
				i++;
			}
			else
			{
				nums[index++] = nums2[j];
				j++;
			}
		}
		while (i < nums1.size())
			nums[index++] = nums1[i++];
		while (j < nums2.size())
			nums[index++] = nums2[j++];

	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int m = nums1.size();
		int n = nums2.size();
		merge(nums1, nums2);
		int k1 = (m + n - 1) / 2;
		int k2 = (m + n) / 2;
		if ((m + n) % 2 == 1)
		{
			return double(nums[k2]);

		}
		else
		{
			return double(nums[k1] + nums[k2]);
		}

	}
};
int main()
{
	Solution s;
	vector<int> v1 = { 1, 2 };
	vector<int> v2 = { 3,4 };
	s.findMedianSortedArrays(v1, v2);
	system("pause");
}