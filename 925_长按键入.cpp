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
	bool isLongPressedName(string name, string typed) {
		int j = 0;
		int count = 0;
		int count_ = 0;
		bool flag = false;
		for (int i = 0; i < typed.size(); i++)
		{
			count = 0;
			count_ = 0;
			flag = false;
			if (name[j] == typed[i])
			{
				while (i + 1 < typed.size() && typed[i] == typed[i + 1])
				{
					i++;
					count++;
				}
				while (j + 1 <name.size() && name[j] == name[j + 1])
				{
					flag = true;
					j++;
					count_++;
				}
				if (!flag)
					j++;
				if (count_ >= 1)
					j++;
				if (count < count_)
					return false;
			
			}
			else
				return false;

		}
		return j == name.size();
	}
};

int main()
{
	Solution s;
	string name = "leelee";
	string typed = "lleeelee";
	cout << s.isLongPressedName(name,typed) << endl;

	system("pause");
}