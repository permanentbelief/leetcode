#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution
{
public:
	int findUnsortedSubarray(vector<int>& nums)
	{	
		stack<int> a;
		stack<int> s;
		int right = 0;
		int left = nums.size();
		for (int i = 0; i < nums.size(); i++)
		{
			while (!s.empty() && nums[i] < s.top())
			{
				left = min(left, (int)s.size()- 1);
				s.pop();
			}
			s.push(nums[i]);
		}
		s.swap(a); //Çå¿Õs
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			while (!s.empty() && nums[i] > s.top())
			{
				right = max(((int)nums.size()-(int)s.size()), right);
				s.pop();
			}
			s.push(nums[i]);
		}
		return (right - left) < 0 ? 0 : right - left + 1;

	}
};
int main()
{
	vector<int> v = { 2, 6, 4, 8, 10, 9, 15 };
	Solution s;
	cout << s.findUnsortedSubarray(v) << endl;
	system("pause");
}