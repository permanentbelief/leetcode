#define _CRT_SECURE_NO_WARNINGS 1 


#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	bool Is_(char c)
	{
		if (c == 'A' || c == 'a' || c == 'e' || c == 'E' || c == 'I' || c == 'i' || c == 'O' || c == 'o' ||
			c == 'U' || c == 'u')
			return true;
		return false;
	}
	string reverseVowels(string s) {
		if (s.empty())
			return s;
		int left = 0;
		int right = s.size() - 1;
		while (left <= right)
		{
			while (left <= right && !Is_(s[left]))
				left++;
			while (left <= right && !Is_(s[right]))
				right--;
			if (left <= right)  // 有可能会产生错误 走到这一步left>right
			swap(s[left], s[right]);

			left++;
			right--;
		}
		return s;
	}
};
int main()
{
	Solution s;
	cout << s.reverseVowels("hello") << endl;
	system("pause");
}