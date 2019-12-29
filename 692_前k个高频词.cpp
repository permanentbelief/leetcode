#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		if (words.empty())
			return words;
		vector<string> vs;
		for (int i = 0; i < words.size(); i++)
		{
			string str = words[i];
        	int count = 1;
			for (int j = i + 1; j < words.size(); j++)
			{
				if (str == words[j])
					count++;
			}
			if (count == k)
				vs.push_back(str);
		}
		return vs;
	}
};

int main()
{
	vector<string> vs = { "i", "love", "leetcode", "i", "love", "coding" };
	int k = 2;
	Solution s;
	vector<string> outcome = s.topKFrequent(vs, k);
	for (auto e : outcome)
	{
		cout << e << " ";
	}
	system("pause");
}