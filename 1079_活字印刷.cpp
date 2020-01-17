#define _CRT_SECURE_NO_WARNINGS 1 


#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	void DFS(string& tiles, string curStr, vector<int>& usedIdx,
		unordered_set<string>& totalString)
	{
		if (!curStr.empty())
		{
			totalString.insert(curStr);
		}
		//��Ǳ�֤����λ������֮�󣬾ͽ�����
		for (int i = 0; i < tiles.size(); i++)
		{
			//��ǰλ�õ��ַ����ù���ֱ������
			if (usedIdx[i])
				continue;
			usedIdx[i] = 1;
			DFS(tiles, curStr + tiles[i], usedIdx, totalString);
			usedIdx[i] = 0;
		}
	}
	int numTilePossibilities(string tiles) {
		if (tiles.empty())
			return 0;
		unordered_set<string> totalString;
		vector<int>usedIdx(tiles.size(), 0);
		DFS(tiles, "", usedIdx, totalString);
		return totalString.size();
	}
};

int main()
{
	Solution s;
	cout << s.numTilePossibilities("AAB") << endl;
	system("pause");
}