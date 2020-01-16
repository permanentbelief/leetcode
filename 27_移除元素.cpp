#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int removeElement(vector<int> nums, int val) {
		if (nums.empty())
			return 0;
		sort(nums.begin(), nums.end());
		int count = 0;
		int flag = -1;
		int begin = 0;
		int end = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[begin] == val)
			{
				flag = begin;
				while (i < nums.size() && end < nums.size() && nums[end] == val)
				{
					end++;
					i++;
				}
				count = end - begin ;
				break;

			}
			begin++;
			end++;
		}
		if (flag != -1 && count != 0) // 1 1 3 3 5 6    count = 2 
		{
			for (int i = flag; i < nums.size() - count; i++)
			{
				nums[i] = nums[i + count];
			}
		}
		while (count--)
		{
			nums.erase(--nums.end());
		}
		return nums.size();
	}
};

int main()
{
	Solution s;
	cout << s.removeElement({ 3,2,2,3}, 3) << endl;
	system("pause");
}