#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		queue<string> q;
		unordered_set<string> wbank(bank.begin(), bank.end());
		unordered_set<string> books(bank.size());
		
		q.push(start);
		int MinNum = 0;
		static char pos[4] = { 'A', 'C', 'G', 'T' };
		while (!q.empty())
		{
			int sz = q.size();
			while (sz--)
			{
				string curStr = q.front();
				q.pop();
				if (curStr == end)
					return MinNum ;
				for (int i = 0; i < curStr.size(); i++)
				{
					string tmp = curStr;
					for (int j = 0; j < 4; j++)
					{
						tmp[i] = pos[j];
						if (books.find(tmp) == books.end()
							&& wbank.find(tmp) != wbank.end())
						{
							books.insert(tmp);
							q.push(tmp);
						}
					}
				}
			}
			MinNum++;
		}
		return 0;
	}
};

int main()
{
	string start = "AACCGGTT";
	string end = "AACCGGTA";
	vector<string> vs = { "AACCGGTA" };
	Solution s;
	cout << s.minMutation(start, end, vs) << endl;
	system("pause");
}