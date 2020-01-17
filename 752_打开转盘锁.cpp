#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <queue>

using namespace std;


// niubi 666!! 终于写出来了
class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		unordered_set<string> wbank;
		for (auto& e : deadends)
		{
			wbank.insert(e);
		}

		static int pos[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		static int HarhMap[2] = { 11, 9 };
		string begin = "0000";
		unordered_set<string> books(deadends.size());
		books.insert(begin);

		if (wbank.find(begin) != wbank.end())
			return -1;

		int minNum = 0;
		queue<string> q;
		q.push(begin);
		while (!q.empty())
		{
			int sz = q.size();
	
			
			while (sz--)
			{
				string curPos = q.front();
				q.pop();
				if (curPos == target)
					return minNum;
				string tmp = curPos;
				for (int i = 0; i < 4; i++)
				{
					
					char ch = tmp[i];
					for (int j = 0; j < 2; j++)
					{
						tmp[i] = pos[( (ch-'0') + HarhMap[j]) % 10] + '0';
						if (wbank.find(tmp) == wbank.end()
							&& books.find(tmp) == books.end())
						{
							books.insert(tmp);
							q.push(tmp);
						}
						else
						{
							continue;
						}
					
					}
					tmp[i] = ch;
				}
			}
			minNum++;
		}

		return -1;
	}
};
 int main()
{

	vector<string> vs = {"0000"};
	Solution s;
	cout << s.openLock(vs,"8888") << endl;
	system("pause");
}