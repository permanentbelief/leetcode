#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
	////法1 暴力法
	//vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	//	vector<int> v;
	//	for (int i = 0; i < nums1.size(); i++)
	//	{
	//		for (int j = 0; j < nums2.size(); j++)
	//		{
	//			if (nums1[i] == nums2[j])
	//			{
	//				v.push_back(nums1[i]);
	//				swap(nums1[i], nums1[nums1.size() - 1]);
	//				swap(nums2[j], nums2[nums2.size() - 1]);
	//				nums1.erase(--nums1.end());
	//				nums2.erase(--nums2.end());
	//				i -= 1;
	//				break;
	//			
	//			}
	//		}
	//	}
	//	return v;

	//}
	//法二
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size())
			return intersect(nums2, nums1);
		unordered_map<int, int> m;
		for (int i = 0; i < nums1.size(); i++)
		{
			m[nums1[i]]++;
		}
		vector<int> v;
		for (int i = 0; i < nums2.size(); i++)
		{
			auto iter = m.find(nums2[i]);
			if (iter != m.end() && iter->second-- > 0)
			{
				v.push_back(iter->first);
			}
		}
		return v;
	}
};
int main()
{
	vector<int> v1 = { 2, 1 };
	vector<int> v2 = { 1, 2};
	Solution s;
	s.intersect(v1,v2);
	system("pause");
}