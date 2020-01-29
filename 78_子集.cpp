#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//class Solution {
//public:
//	vector<vector<int>> subsets(vector<int>& nums) {
//		vector<vector<int> > res(1);
//		for (int i = 0; i<nums.size(); i++){
//			int cnt = res.size();
//			for (int j = 0; j<cnt; j++){
//				vector<int> tmp = res[j];
//				tmp.push_back(nums[i]);
//				res.push_back(tmp);
//			}
//		}
//		return res;
//	}
//};
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int> > res;
		vector<int> tmp;
		helper(res, tmp, nums, 0);
		return res;
	}
	void helper(vector<vector<int> >& res, vector<int>&tmp, vector<int>& nums, int level){
		if (tmp.size() <= nums.size()){
			res.push_back(tmp);
		}
		for (int i = level; i<nums.size(); i++){
			tmp.push_back(nums[i]);
			helper(res, tmp, nums, i + 1);
			tmp.pop_back();
		}
	}
};
int main()
{
	Solution s;
	vector<int> nums = { 1, 2, 3 ,4};
	vector<vector<int>> outcome = s.subsets(nums);
	for (auto e : outcome)
	{
		for (auto ee : e)
		{
			cout << ee << " ";
		}
		cout << endl;
	}
	cout << endl;
	system("pause");
}