#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


#include <unordered_map>
class Solution {
public:
	struct Node
	{
		int i;
		int j;
		int val;
		Node(int _i, int _j, int _val)
			:i(_i)
			, j(_j)
			, val(_val)
		{

		}
		bool operator<(const Node& n) 
		{
			return val < n.val;
		}
	};
	struct cmp
	{
		bool operator()(Node& n1, Node& n2) const
		{
			return n1.val < n2.val ;
		}
	};
	vector<int> smallestRange(vector<vector<int>>& nums) {
		vector<int> v;
		priority_queue<Node,vector<Node>, cmp> pq;
		int max_ = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			pq.push(Node{ i, 0, nums[i][0] });
			max_ = max(max_, nums[i][0]);
		}
		return v;
	}
};
typedef union
{
	int a;
	char c;
}A;
int main()
{
	
	A a;
	a.a = 1;
	char c = *(char*)&(a.a);
	if (a.c == 1)
	{
		cout << "yes" << endl;
	}
	
	system("pause");
}