#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>

using namespace std;


class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n <= 0)
			return false;
		while (n> 0)
		{
			int temp = n / 3;
			if (temp >= 3 && temp % 3 != 0)
				return false;
			n /= 3;
		}
		return true;


	}
};

class Solution1 {
public:
	bool isPowerOfFour(int num) {
		if (num == 1)
			return true;
		else if (num <= 0)
			return false;
		else
			return ((num &(num - 1)) == 0); // 1000 0111
	}
};
int main()
{
	//Solution s;
	//cout << s.isPowerOfThree(19684) << endl;
	Solution1 s1;
	cout << s1.isPowerOfFour(16) << endl;
	system("pause");
}