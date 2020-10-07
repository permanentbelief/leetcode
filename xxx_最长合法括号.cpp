#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>


#include <set>
#include <map>


using namespace std;
//
//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		int start = 0;
//		int right = 0;
//		int ans = 0;
//		map<char, int> mymap;
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (mymap.find(s[i]) != mymap.end())
//			{
//				start = max(start, mymap[s[i]]);
//			}
//			mymap[s[i]] = i;
//			ans = max(ans, i - start + 1);
//		}
//		return ans;
//	}
//};



class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> st;
		st.push(-1);

		int max_ = 0;
		for (int i = 0; i < s.size(); i++)
		{
			while (s[i] == ')' && st.top() != -1 && s[st.top()] == '(')
			{
				s[i] = '1';
				s[st.top()] = '1';
				st.pop();
			}
			if (s[i] != '1')
				st.push(i);
		}


		for (int i = 0; i < s.size(); i++)
		{
			cout << s[i] << " ";
		}

		cout << endl;


		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '1')
			{
				int sums = 0;
				while (i < s.size() && s[i] == '1')
				{
					sums++;
					i++;
				}
				max_ = max(max_, sums);
			}
		}

		return max_;
	}
};

int main()
{
	Solution s;
	//vector<int>  vv = { 3,4,-1,1};
	string str = "()(())";
	cout << s.longestValidParentheses(str) <<endl;

	system("pause");
}