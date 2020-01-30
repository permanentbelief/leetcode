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
	vector<int> sortedSquares(vector<int>& A) {
		vector<int> v(A.size());
		int start = 0;
		int end = A.size() - 1;
		int k = A.size() - 1;
		while (start <= end)
		{
			if (-A[start] > A[end])
			{
				v[k--] = A[start] * A[start];
				start++;
			}
			else
			{
				v[k--] = A[end] * A[end];
				end--;
			}
		}
		return v;
	}
};
int main()
{
	Solution s;
	vector<int> v = { 4, -1, 0, 3, 10 };
	s.sortedSquares(v);
	system("pause");
}