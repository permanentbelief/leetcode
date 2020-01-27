#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

//
//// ³¬Ê±
//class Solution {
//public:
//	bool containsNearbyDuplicate(vector<int>& nums, int k) {
//		if (nums.empty())
//			return false;
//		//  sort(nums.begin(), nums.end());
//		if (nums.size() == k)
//		{
//			sort(nums.begin(), nums.end());
//			for (int i = 0; i < nums.size() - 1; i++)
//			{
//				if (nums[i] == nums[i + 1])
//					return true;
//			}
//			return false;
//		}
//		for (int i = 0; i < nums.size(); i++)
//		{
//			int m = i;
//			for (int j = i + 1; j < nums.size(); j++)
//			{
//				if (nums[m] == nums[j])
//				{
//					int min = j - m;
//					if (min <= k)
//						return true;
//				}
//				
//			}
//		}
//		return false;
//	}
//};


// ¹þÏ£
class Solution
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		unordered_map<int, int>map;
		for (int i = 0; i < nums.size(); i++)
		{
			auto iter = map.find(nums[i]);
			if (iter != map.end())
			{
				if (i - iter->second <= k)
					return true;
			}

				map[nums[i]] = i;
			
		}
		return false;
	}
};
int main()
{
	vector<int> nums = { 1, 2, 2,3 };
	int k = 0;
	Solution s;
	cout << s.containsNearbyDuplicate(nums, k) << endl;

	system("pause");
}