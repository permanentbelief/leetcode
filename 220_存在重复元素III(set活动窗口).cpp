#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
	set<int> record; // »î¶¯´°¿Ú
	for(int i = 0; i < nums.size(); i++)
	{
		auto s = record.lower_bound((double)nums[i] - t);
		if (s != record.end() && *s <= (double)nums[i] + t)
			return true;
		record.insert(nums[i]);
		if (record.size() == k + 1)
			record.erase(nums[i - k]);
	}
	return false;
}
int main()
{
	
	system("pause");
}