#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class UF
{
public:
	vector<int> size;
	int cnt;
	vector<int> parent;

	UF(int n)
	{
		parent.resize(n);
		size.resize(n);
		cnt = n;
		for (int i = 0; i < n; i++)
		{
			parent[i] = i;
			size[i] = 1;
		}
	}

	bool connected(int m, int n)
	{
		int root_m = find(m);
		int root_n = find(n);
		return root_m == root_n;
	}
	int find(int x)
	{
		while (parent[x] != x)
		{
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}
	void unioned(int m, int n)
	{
		int root_m = find(m);
		int root_n = find(n);

		if (root_m == root_n)
			return;

		//小树接到大树下
		if (size[root_m] > size[root_n])
		{
			parent[root_n] = root_m;
			size[root_m] += size[root_n];
		}
		else
		{
			parent[root_m] = root_n;
			size[root_n] += size[root_m];
		}
		cnt--;
	}
	int count()
	{
		return cnt;
	}
};

class UnionFind
{
public:
	vector<int> parent;
	UnionFind(vector<string> &names)
	{
		int len = names.size();
		for (int i = 0; i < len; i++)
			parent.push_back(i);
	}
	int find(int i)
	{
		if (parent[i] != i)
			parent[i] = find(parent[i]);
		return parent[i];
	}
	void Union(int x, int y)
	{
		int rootx = find(x), rooty = find(y);
		if (rootx != rooty)
			parent[rooty] = rootx;
	}
};

#include <unordered_map>
#include <map>
#include <set>

//class Solution {
//public:
//	vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
//		unordered_map<string, pair<int, int>> mp;
//		unordered_map<int, string> dict;
//		for (int i = 0; i < names.size(); i++)
//		{
//			int j;
//			for (j = 0; j < names[i].size(); j++)
//			if (names[i][j] == '(')break;
//			dict[i] = names[i].substr(0, j);
//			mp[names[i].substr(0, j)] = make_pair(atoi(names[i].substr(j + 1, names[i].size() - 2 - j).c_str()), i);
//		}
//		UnionFind uf(names);
//
//		for (int i = 0; i < synonyms.size(); i++)
//		{
//			int bound = 0;
//			for (int j = 0; j < synonyms[i].size(); j++)
//			if (synonyms[i][j] == ',')
//				bound = j;
//			string a = dict[uf.find(mp[synonyms[i].substr(1, bound - 1)].second)];
//			string b = dict[uf.find(mp[synonyms[i].substr(bound + 1, synonyms[i].size() - bound - 2)].second)];
//			if (a > b)swap(a, b);
//			if (mp.find(a) != mp.end() && mp.find(b) != mp.end())
//				uf.Union(mp[a].second, mp[b].second);
//		}
//		vector<string> res(mp.size());
//
//		unordered_map<string, pair<int, int>>::iterator it;
//		set<int> roots;
//		for (it = mp.begin(); it != mp.end(); it++)
//		{
//			int r = uf.find((*it).second.second);
//			roots.insert(r);
//			if (res[r].empty())
//				res[r] += dict[r];
//			if (r != (*it).second.second)
//				mp[dict[r]].first += (*it).second.first;
//		}
//		set<int>::iterator itx;
//		for (itx = roots.begin(); itx != roots.end(); itx++)
//			res[*itx] += '(' + to_string(mp[dict[*itx]].first) + ')';
//		int p = 0;
//		for (int i = 0; i < res.size(); i++)
//		if (!res[i].empty())
//			res[p++] = res[i];
//		res.erase(res.begin() + p, res.end());
//		return res;
//	}
//};



class Solution {
public:
	unordered_map<string, string> Tree; // 并查集数组，保存每个节点的父亲
public:
	string findRoot(string key) { // 构造并查集，通过父亲找祖先
		if (Tree.count(key) == 0) return key;
		auto ancestor = findRoot(Tree[key]);
		Tree[key] = ancestor;
		return ancestor;
	}
	vector<string> trulyMostPopular(vector<string>& names,
		vector<string>& synonyms) {
		for (auto& name_pair : synonyms) {
			int comma_ind = name_pair.find(',');
			string n1 = name_pair.substr(1, comma_ind - 1);
			string n2 = name_pair.substr(comma_ind + 1,
				int(name_pair.size()) - comma_ind - 2);
			n1 = findRoot(n1), n2 = findRoot(n2); // 这里需要注意，比较大小时不是直接比较 n1 和 n2，而是比较他们的根！否则就没有意义啦！
			if (n1 != n2) {
				if (n1 < n2)
					Tree[n2] = n1;
				else
					Tree[n1] = n2;
			}
		}
		unordered_map<string, int> hash_map;
		for (auto& name_str : names) {
			int t_ind = name_str.find('(');
			string name = name_str.substr(0, t_ind);
			int freq = atoi(
				name_str.substr(t_ind + 1, int(name_str.size()) - t_ind - 2).c_str());
			hash_map[findRoot(name)] += freq;
		}
		vector<string> ans;
		for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++) {
			string tmp = iter->first + "(" + to_string(iter->second) + ")";
			ans.push_back(tmp);
		}
		return ans;
	}
};

class Solution1
{

};
//int main()
//{
//	Solution s;
//
//	vector<string>names = { "John(15)", "Jon(12)", "Chris(13)", "Kris(4)", "Christopher(19)" };
//	vector<string> synonyms = { "(Jon,John)", "(John,Johnny)", "(Chris,Kris)", "(Kris,Christopher)" };
//	s.trulyMostPopular(names, synonyms);
//
//	system("pause");
//}