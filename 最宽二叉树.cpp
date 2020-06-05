#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


int count1 = 0;
void merge(vector<int>& arr, int start, int mid, int right, int end)
{
	vector<int> res;
	int left_index = start;
	int right_index = mid + 1;
	while (left_index <= mid && right_index <= end)
	{
		if (arr[left_index] <= arr[right_index])
		{
			count1 += (end - right_index + 1)*arr[left_index];
			res.push_back(arr[left_index]);
			left_index++;

		}
		else
		{
			res.push_back(arr[right_index]);
			right_index++;
		}
	}
	for (int i = left_index; i <= mid; i++)
	{
		res.push_back(arr[i]);
	}
	for (int i = right_index; i <= end; i++)
	{
		res.push_back(arr[i]);
	}
	for (int i = start; i <= end; i++)
	{
		arr[i] = res[i - start];
	}
}
//void mergeSort(vector<int> &arr, int start, int end) {
//
//	int mid = start + (end - start) / 2;
//	if (mid > start) {
//		mergeSort(arr, start, mid);
//	}
//	if (end > mid + 1) {
//		mergeSort(arr, mid + 1, end);
//	}
//	merge(arr, start, mid, end);
//}
//int calcMonoSum(vector<int> A, int n) {
//	// write code here
//	if (n < 2) {
//		return 0;
//	}
//	mergeSort(A, 0, n - 1);
//	return count;
//}

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

template<class T>
class NamedObject
{

public:
	NamedObject(std::string & s, const T &t)
		:str(s), objectValue(t)
	{
		std::cout << "const invoke!" << std::endl;
	}

	//���ڳ�Ա�����д������ú�const���ͣ����Ա���Ҫ
	//�Զ���operator=����������Ϊ���ú�const���Ͷ�����
	//���¸�ֵ
	NamedObject& operator=(const NamedObject & rhs)
	{
		// std::cout << "operator= invoke!" << std::endl;
		str = rhs.str;
		objectValue = rhs.objectValue;
		return *this;
	}

private:
	std::string & str;
	const T objectValue;
};

//int main()
//{
//	//ע��const char *ֻ��ת����std::string������ת����std::string&�����������������ܺϲ���һ��
//	std::string s = "hello";
//	NamedObject<int> obj1(s, 1);
//	NamedObject<int> obj2(obj1);
//	obj2 = obj1;
//	system("pause");
//}

class Solution {
public:
	class TreeNode
	{
	public:
		TreeNode* nexts[26];
		int cnt = 0;
		TreeNode()
			:cnt(1)
		{
			for (int i = 0; i < 26; i++)
			{
				nexts[i] = nullptr;
			}
		}

	};
	string longestCommonPrefix(vector<string>& strs) {
		string str;
		if (strs.size() == 0)
			return str;
		TreeNode* root = new TreeNode();
		for (int i = 0; i < strs.size(); i++)
		{
			if (strs[i] == "")
				return "";
			TreeNode* cur = root;
			for (int j = 0; j < strs[i].size(); j++)
			{
				if (cur->nexts[strs[i][j] - 'a'] == nullptr)
				{
					cur->nexts[strs[i][j] - 'a'] = new TreeNode();
				}
				else
				{
					cur->nexts[strs[i][j] - 'a']->cnt++;
				}
				cur = cur->nexts[strs[i][j] - 'a'];
			}
		}
		TreeNode* cur = root;
		bool f = true;
		while (1)
		{
			int count = 0;
			int flag = 0;
			TreeNode* tmp = nullptr;
			for (int i = 0; i < 26; i++)
			{
				
				if (cur->nexts[i] && cur->nexts[i]->cnt >= 1)
				{
					count++;
					tmp = cur->nexts[i];
					flag = i;
				}
			}
			if (count == 1)
			{
				cur = tmp;
				str += flag + 'a';
			}
			else if (count != 1)
			{
				f = false;
				break;
			}

			if (!f)
				break;
		}
		return str;
	}
};


string LongestCommon(vector<string>& strs)
{
	if (strs.size() == 0)
	{
		return "";
	}
	string ans = strs[0];
	string res = "";
	for (int i = 0; i < strs.size(); i++)
	{
		
		for (int j = 1; j < strs.size(); j++)
		{
			if (ans[i] != strs[j][i])
				return res;
		}
		res += ans[i];
		if (res == "")
			return res;
	}
}


#include <unordered_map>

void dfs(vector<vector<int>>& costs, int left, int right, int& min_, int sum, int cur)
{
	if (left == 0 && right == 0)
	{
		min_ = min(sum, min_);
	}
	for (int i = cur; i < costs.size(); i++)
	{
		if (left >= 1)
			dfs(costs, left - 1, right, min_, sum + costs[cur][0], i + 1);
		if (right >= 1)
			dfs(costs, left , right - 1, min_, sum + costs[cur][1], i + 1);
	}

}
int twoCitySchedCost(vector<vector<int>>& costs) {
	int left = costs.size() / 2;
	int right = costs.size() / 2;
	int min_ = INT_MAX;
	dfs(costs, left, right, min_, 0, 0);
	return min_;
}


int  Get(stack<int>& s)
{
	int result = s.top();
	s.pop();
	if (s.empty())
		return result;
	else
	{
		int last = Get(s);
		s.push(result);
		return last;
	}
}
void reverse(stack<int>& s)
{
	if (s.empty())
		return;
	int i = Get(s);
	reverse(s);
	s.push(i);
}



/*
���캯�� ֮��ʼ���б�

ִ�г�ʼ���б�
ִ�г�ʼ���б��еĸ�ֵ{}�еĹ��첿�֡�


*/
//class A
//{
//public:
//	//Ĭ�ϵĹ��캯��
//	A()
//	{
//		cout << "A()" << endl;
//	}
//	//�������캯��
//	A(const A& a)
//	{
//		cout << "A(const A&)" << endl;
//	}
//	//��ֵ����
//	A& operator=(const A& a)
//	{
//		cout << "A=(const A&)" << endl;
//		return *this;
//	}
//};
//class B
//{
//public:
//	//�Զ���Ĺ��캯��
//	B(A& _a)
//	{
//		a = _a;
//		cout << "B(A&)" << endl;
//	}
//	//Ĭ�Ϲ��캯��
//	B()
//	{
//		cout << "B()" << endl;
//	}
//private:
//	A a;
//};


//class A
//{
//public:
//	//Ĭ�ϵĹ��캯��
//	A()
//	{
//		cout << "A()" << endl;
//	}
//	//�������캯��
//	A(const A& a)
//	{
//		cout << "A(const A&)" << endl;
//	}
//	//��ֵ����
//	A& operator=(const A& a)
//	{
//		cout << "A=(const A&)" << endl;
//		return *this;
//	}
//};
//class B
//{
//public:
//	//�Զ���Ĺ��캯��
//	B(A& _a)
//		:a(_a)
//	{
//		cout << "B(A&)" << endl;
//	}
//	//Ĭ�Ϲ��캯��
//	B()
//	{
//		cout << "B()" << endl;
//	}
//private:
//	A a;
//};
//
//int Get(vector<int>& v)
//{
//	int left = 0;
//	int right = v.size() - 1;
//	while (left < right)
//	{
//		int mid = left + (right - left) / 2;
//		if (mid >= right)
//		{
//			mid = right;
//		}
//		else
//		{
//			left = mid + 1;
//		}
//	}
//}

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(3);
	root->right = new TreeNode(2);
	root->right->right = new TreeNode(9);

	if (root == nullptr)
		return 0;
	int res = 1;
	deque<int> lists;
	lists.push_back(1);
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		int sz = (int)q.size();
		while (sz--)
		{
			auto e = q.front();
			q.pop();
			int a = lists.front();
			//cout << a << endl;
			lists.pop_front();
			if (e->left)
			{
				q.push(e->left);
				lists.push_back(2 * a);
			}
			if (e->right)
			{
				q.push(e->right);
				lists.push_back(2 * a + 1);

			}
			if (lists.size() >= 2)
			res = max(res, lists.back() - lists.front() + 1);
		}

	}
	cout << res << endl;
	system("pause");
}


//int main()
//{
//	stack<int> s ;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//
//	reverse(s);
//	
//	system("pause");
//
//};

/*
�ַ��� string
��ϣ hash(key-value) 
list (�б���������ʵ�ֶ��еĹ��ܣ����ǹ��ܱ�ʵ�ֶ��и�ǿ��)
����set��Ԫ�صļ��ϣ�
���򼯺�zset



MSET ʵ�ֺã��޸�ֵ��ʱ��ֱ�Ӷ�key��Ӧ���ֶν����޸ģ�����������SET�����л�һ��ֵ
����ȥ�޸ģ��ڴ���redis��

SETNX ���÷ֲ�ʽ����ֻ������һ�� ���߳���


��������

���ӵ��Ķ������ڿ������ȵȣ����͵����ǿ�ȵ�
������redis�ļ�����ʵ�ֵġ�

INCR article:readcount:{����ID}
ÿһ�α��򿪣���ִ̨��һ������͵���һ�Σ�
GET article:readcount:{����ID}


Web��Ⱥsession����
redisʵ��session����



*/