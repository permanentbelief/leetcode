#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <vector>
#include <string>

using namespace std;


// VS下 正确都可以  leetcode上跑不过 已通过 第二个for循环的位置
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		vector<int> row;
		vector<int> col;
		if (matrix.empty())
			return;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] == 0)
				{
					row.push_back(i);
					col.push_back(j);
				}
			}
		}
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < col.size(); j++)
			{
				matrix[i][col[j]] = 0;
			}
		}
	
			for (int j = 0; j < row.size(); j++)  //for
			{
				for (int i = 0; i < matrix[0].size(); i++)
				{
					matrix[row[j]][i] = 0;
				}
			}
	


	}
};

int main()
{
	vector<vector<int>> v = { {5,1,2,3}, { 0,4,5,2 }, {1,3,1,0 } };
	//[[0,1,2,0],[3,4,5,2],[1,3,1,5]]
	Solution s;
	s.setZeroes(v);
	system("pause");
	
}