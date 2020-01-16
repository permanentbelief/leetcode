#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	void DFS(vector<vector<int>>& ret, vector<int>&candidates, vector<int>& tmp, int sum, int target
		, int prevPos)
	{
		if (sum >= target)
		{
			if (sum == target)
				ret.push_back(tmp);
			return;
		}
		for (int i = prevPos; i < candidates.size(); i++)
		{
			//保存当前元素
			tmp.push_back(candidates[i]);
			DFS(ret, candidates, tmp, sum + candidates[i], target, i);


			tmp.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> ret;
		vector<int> tmp;
		DFS(ret, candidates, tmp, 0, target, 0);
		return ret;

	}
};

int main()
{
	vector<vector<int>> ret;
	Solution s;
	vector<int> candidates = { 2, 4 };
	ret = s.combinationSum(candidates, 8);
	for (auto e : ret)
	{
		for (auto &i : e)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	system("pause");
}