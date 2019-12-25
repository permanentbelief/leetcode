#define _CRT_SECURE_NO_WARNINGS 1 

#include <string>
#include <iostream>
using namespace std;

//�����ݹ鷨  ����ʱ������
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
		// left = right ��ʱ�򣬴�ʱ����������һ����϶�����Ĵ��ĳ���������
		// right = left + 1 ��ʱ�򣬴�ʱ��������������һ���ַ������Ĵ��ĳ�����ż��
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
		// ����ҪС�ģ����� while ѭ��ʱ��ǡ������ s.charAt(i) != s.charAt(j)����˲���ȡ i������ȡ j
		return s.substr(i + 1, j - i - 1);
	}

public:


	string longestPalindrome(string s) {
		// ����
		int size = s.size();
		if (size < 2) {
			return s;
		}

		int maxLen = 1;
		string res = s.substr(0, 1);

		// ����λ��ö�ٵ� len - 2 ����
		for (int i = 0; i < size - 1; i++) {
			string oddStr = centerSpread(s, i, i);  //������ odd    ���Ŀ϶�����ͬ����ĸ
			string evenStr = centerSpread(s, i, i + 1);  //ż���� even   left+1 = right  
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