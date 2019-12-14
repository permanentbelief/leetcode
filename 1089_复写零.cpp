#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	void duplicateZeros(vector<int>& arr) {

		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] == 0)
			{
				int end = arr.size() - 1;
				for (int j = end; j > i; j--)
				{
					arr[j] = arr[j - 1];
				}
				i++;
			}
		}

	}
};

int main()
{
	Solution s;
	vector<int> v;


	v.push_back(1);
	v.push_back(0);
	v.push_back(2);
	v.push_back(3);
	v.push_back(0);
	v.push_back(4);
	v.push_back(5);
	v.push_back(0);


	s.duplicateZeros(v);
	system("pause");
}