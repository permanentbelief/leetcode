#define _CRT_SECURE_NO_WARNINGS 1 



#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution{
public:
	int singleNumber(vector<int>& nums)
	{
		int count = 0;
		int result = 0;
		for (int i = 0; i < 32; i++)
		{
			count = 0;
			for (int j = 0; j < nums.size(); j++)
			{
				if ( (nums[j] >> i  & 1) == 1)
					count++;
			}
			if (count % 3 != 0 )
			{
				result = result | 1 << i;
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 1, 1, 1, 2, 3, 3, 3 ,2,2, 4,4,4,108,190,108,108};
	cout << s.singleNumber(v) << endl;

	cout << (5 | 2) << endl; // 101  010

	
	system("pause");
}