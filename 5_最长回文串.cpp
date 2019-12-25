#define _CRT_SECURE_NO_WARNINGS 1 

#include <string>
#include <iostream>
using namespace std;

//暴力递归法  超出时间限制
//class Solution {
//public:
//	string longestPalindrome(string s) {
//
//		string temp = ""; 
//		string r_temp; 
//		string max;
//		for (int i = 0; i < s.size(); i++)
//		{
//			temp = "";
//			for (int j = i; j < s.size(); j++)
//			{
//				temp += s[j];
//				r_temp = temp;
//				reverse(temp.begin(), temp.end());
//				if (r_temp == temp)
//				{
//					if (temp.size() > max.size())
//						max = temp;
//				}
//				temp = r_temp;
//			}
//		}
//		return max;
//	}
//};
//int main()
//{
//	Solution s;
//	cout << s.longestPalindrome("niddsfqnilxlplselqajrhqcyzvekzqlxgddjoir") << endl;
//	system("pause");
//}


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

private:

	string centerSpread(string& s, int left, int right) {
		// left = right 的时候，此时回文中心是一个空隙，回文串的长度是奇数
		// right = left + 1 的时候，此时回文中心是任意一个字符，回文串的长度是偶数
		int size = s.size();
		int i = left;
		int j = right;
		while (i >= 0 && j < size) {
			if (s[i] == s[j]) {
				i--;  // -1  i+1       0
				j++;  // 1   j-i-1    1
			}
			else {
				break;
			}
		}
		// 这里要小心，跳出 while 循环时，恰好满足 s.charAt(i) != s.charAt(j)，因此不能取 i，不能取 j
		return s.substr(i + 1, j - i - 1);
	}

public:


	string longestPalindrome(string s) {
		// 特判
		int size = s.size();
		if (size < 2) {
			return s;
		}

		int maxLen = 1;
		string res = s.substr(0, 1);

		// 中心位置枚举到 len - 2 即可
		for (int i = 0; i < size - 1; i++) {
			string oddStr = centerSpread(s, i, i);  //奇数个 odd    中心肯定是相同的字母
			string evenStr = centerSpread(s, i, i + 1);  //偶数个 even   left+1 = right  
			string maxLenStr = oddStr.size() > evenStr.size() ? oddStr : evenStr;
			if (maxLenStr.length() > maxLen) {
				maxLen = maxLenStr.size();
				res = maxLenStr;
			}
		}
		return res;
	}
};
int main()
{
	Solution s;
	cout << s.longestPalindrome("bb") << endl;
	system("pause");
}