#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
//class Solution {
//public:
//	static bool cmp(pair<int, int>& a, pair<int, int>& b)
//	{
//		if (a.first == b.first)
//		{
//			return a.second > b.second;
//		}
//		return a.first < b.first;
//
//	}
//	int maxEnvelopes(vector<vector<int>>& envelopes) {
//		if (envelopes.empty())
//			return 0;
//		vector<pair<int, int>> vp(envelopes.size());
//		for (int i = 0; i < envelopes.size(); i++)
//		{
//			vp[i] = pair<int, int>(envelopes[i][0], envelopes[i][1]);
//		}
//
//		sort(vp.begin(), vp.end(), cmp);
//
//		vector<int> v;
//		v.push_back(vp[0].second);
//		//bool flag = false;
//		for (int i = 1; i < vp.size(); i++)
//		{
//			//if (flag == false && vp[i - 1].first == vp[i].first)
//			//	continue;
//			if (vp[i].second > v.back())
//			{
//				v.push_back(vp[i].second);
//			}
//			else
//			{
//				/*flag = true;
//				continue;*/
//				int it = lower_bound(v.begin(), v.end(), vp[i].second) - v.begin();
//				v[it] = vp[i].second;
//			}
//			//flag = false;
//		}
//		return v.size();
//	}
//};

#include <map>
//class Solution {
//public:
//	string largestNumber(vector<int>& cost, int target) {
//		vector<vector<int>> f(10, vector<int>(target + 1));
//
//		for (int i = 1; i <= target; i++) f[0][i] = -1e8;
//		for (int i = 1; i <= 9; i++)
//		for (int j = 0; j <= target; j++)
//		{
//			f[i][j] = f[i - 1][j];
//			if (j >= cost[i - 1]) f[i][j] = max(f[i][j], f[i][j - cost[i - 1]] + 1);
//		}
//
//		if (f[9][target] < 1) return "0";
//		string res;
//
//		for (int i = 9, j = target; i; i--)
//		while (j >= cost[i - 1] && f[i][j] == f[i][j - cost[i - 1]] + 1)
//		{
//			res += to_string(i);
//			j -= cost[i - 1];
//		}
//
//		return res;
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int> v = { 6, 10, 15, 40, 40, 40, 40, 40, 40 };
//	int target = 47;
//	string str = "0110";
//	cout << s.largestNumber(v, target) << endl;
//
//
//	//vector<int> v = { { 978196917, 202623379, 552387129, 754071585, 366121947, 444381377, 774799689, 300436332, 851324710, 360072179 }
//	//	 };
//	//int k = 6;
//	//
//	//s.findLeastNumOfUniqueInts(v, k);
//	//int k = 10;
//	
//
//	vector<vector<int>> e = { { 3, 4 }, { 2, 3 }, { 1, 2 } };
//	// { { 2, 100 }, { 3, 200 }, { 4, 300 }, { 5, 500 }, { 5, 400 }, { 5, 250 }, { 6, 370 }, { 6, 360 }, { 7, 380 } };
//	//s.findRightInterval(e);
//
//		
//	//vector<int> endTimes = { 3, 5, 5, 6 };
//	//vector<int> profit = { 50, 10, 40, 70 };
//	
//	/*s.jobScheduling(s1, endTimes, profit);*/
//	system("pause");
//}





using namespace std;

//const int N = 3e5 + 200;
//
//int n;
//int m;
//int a[N];
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	deque<int> dq;
//
//	int max_ = 0;
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		sum += a[i];
//		while (dq.size() && i - dq.front() >= m)
//		{
//
//			sum -= a[dq.front()];
//			dq.pop_front();
//		}
//
//		while (dq.size() && a[i] > a[dq.front()])
//		{
//			sum -= a[dq.back()];
//			dq.pop_back();
//		}
//		max_ = max(max_, sum);
//		dq.push_back(i);
//	}
//	cout << max_ << endl;
//	system("pause");
//}

/*

int a[N];
int f[N];
int n;
int m;

int main()
{
cin >> n ;
for(int i =1; i <= n; i++)
{
cin >> a[i];
a[i + n] = a[i];
}
for(int i = 1; i <= 2*n - 1; i++)
{
a[i] += a[i- 1];
}

//前缀和
deque<int> dq;

int ans = 0; // 计数
for(int i = 1; i <= 2*n - 1; i++)
{
while(dq.size() && i - dq.front() > n)
{
// ans++;
dq.pop_front();
}
while(dq.size() && a[dq.back()] >= a[i])
dq.pop_back();
dq.push_back(i);
//将队列中的最小值每一次减去 队头数据的值，判断从 i-n 位置出发的n个数
//中最小的数 front() 减去 队头的数据是否大于等于 0
if(i - n + 1 > 0 && a[dq.front()] - a[i - n] >= 0)
ans++;
}
cout << ans << endl;

}

*/



//#include <unordered_map>
//using namespace std;
//int main()
//{
//
//	int a[10] = { 0 };
//	a[0] = 4;
//	a[1] = 4;
//	a[2] = 2;
//	a[3] = 5;
//	int n = 10;
//	int i = 0;
//		for (i = 0; i < n; i++)
//			a[i] = a[i] * (n + 1);
//
//		for (i = 0; i < n; i++)
//			a[a[i] / (n + 1) - 1]++;
//
//		for (i = 0; i < n; i++)
//			cout << a[i] % (n + 1) << " ";
//		cout << endl;
//
//		system("pause");
//}


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	struct com
	{
		static bool operator < (ListNode* l1, ListNode* l2) const
		{
			if (l1->val < l2->val)
				return true;
			else
				return false;
	    }

	};
	// 7.20 二刷
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* duumy = new ListNode(-1);
		ListNode* cur = duumy;
		if (lists.size() == 0)
			return nullptr;

		priority_queue<ListNode*, vector<ListNode*>, com> pq;
		for (int i = 0; i < lists.size(); i++)
		{
			if (lists[i] == nullptr)
				continue;
			pq.push(lists[i]);
		}
		while (pq.size())
		{
			ListNode* nextNode = pq.top();
			pq.pop();
			cur->next = nextNode;
			cur = cur->next;
			if (curNode->next != nullptr)
				pq.push(curNode->next);
		}
		return duumy->next;
	}
};

int main()
{
	Solution s;
}
//

//int main()
//{
//	string s = "AaABbBcBbcvQv";
//	//cin >> s;
//	stack<int> sta;
//	vector<int> v(s.size());
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (sta.size())
//		{
//			int top = sta.top();
//			char ch = s[top];
//			sta.pop();
//			if (sta.size())
//			{
//				if (s[sta.top()] == s[i])
//				{
//					v[sta.top()] = 1;
//					v[top] = 1;
//					v[i] = 1;
//					sta.pop();
//				}
//			}
//			sta.push(top);
//		}
//		sta.push(i);
//	}
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//	string str;
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (v[i] == 0)
//			str += s[i];
//	}
//	cout << str << endl;
//
//	
////	vector<int> c(s.size());
//	int j = -1;
//	for (int i = 0; i < s.size() - 2; i++)
//	{
//		if (s[i] == s[i + 2] && s[i] != s[i + 1])
//		{
//			j = i + 2;
//			i++;
//		}
//		else if (i != j)
//			cout << s[i] << " ";
//	}
//
//	//cout << endl;
//	system("pause");
//	
//}
//
//const int N = 3e5 + 100;
//int n, m;
//
//int a[N];
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//		a[i] += a[i - 1];
//	}
//	// 6 4
//	// 1 -3 5 1 -2 3
//	// 1 -2 3 4  2 5
//	deque<int> dq;
//	int ans = INT_MIN;
//	dq.push_back(0);
//	for (int i = 1; i <= n; i++)
//	{
//		while (dq.size() && a[i] <= a[dq.back()])
//			dq.pop_back();
//		dq.push_back(i);
//		if (i  >= m)
//			ans = max(ans, a[i] - a[i - m ]);
//		if (i - dq.front() >= m)
//			ans = max(ans, a[i] - a[dq.front()]);
//
//	}
//
//	cout << ans << endl;
//	system("pause");
//}

//int main()
//{
//	vector<int> nums = { 0, 0 };
//	cout << longestConsecutive(nums) <<endl;
//	system("pause");
//	//cout << str << endl;
//}


//using namespace std;
//
//using namespace std;
//
//
//const int N = 2e4 + 100;
////const int M = 1e9 + 10;
//
//int n, m, k;
//int f[N];
//int rank1[N];
//
//int find(int x)
//{
//	if (x == f[x])
//		return x;
//	else return f[x] = find(f[x]);
//}
//
//void Union(int x, int y)
//{
//	int fa = find(x);
//	int fb = find(y);
//	if (fa == fb)
//		return;
//	else
//	{
//		if (rank1[fa] < rank1[fb])
//		{
//			rank1[fb] += rank1[fa];
//			f[fa] = fb; // 指向fb;
//		}
//		else
//		{
//			rank1[fa] += rank1[fb];
//			f[fb] = fa;
//		}
//	}
//
//}
//int main()
//{
//	cin >> n >> m >> k;
//	for (int i = 1; i <= n; i++) f[i] = i, rank1[i] = 1;
//
//	for (int i = 1; i <= k; i++)
//	{
//		int a, b = 0;
//		cin >> a >> b;
//		Union(a, b);
//
//	}
//
//	for (int i = 1; i <= n; i++)
//		cout << rank1[i] << " ";
//	cout << endl;
//	for (int i = 1; i <= n; i++)
//		cout << f[i] << " ";
//	cout << endl;
//	int ans = INT_MAX;
//	int flag = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (f[i] == i)
//		{
//			if (abs(rank1[i] - m) <= ans)
//			{
//				if (flag == 0 || rank1[i] < flag)
//				{
//					flag = rank1[i];
//					ans = abs(rank1[i] - m);
//				}
//
//			}
//		}
//	}
//	cout << ans << endl;
//
//}