#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
//
//class Solution {
//public:
//	bool s = false;
//	void dfs(vector<vector<char>>& board, string& word, int x, int y, int cur, bool& ret)
//	{
//		static int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
//
//		if (board[x][y] != word[cur])
//			return;
//
//		// cout << "cur : " << cur << "  " <<  word[cur] << " ";
//		if (cur == word.size() - 1)
//		{
//			ret = true;
//			return;
//		}
//		char ch = board[x][y];
//		board[x][y] = '.';
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = x + pos[i][0];
//			int ny = y + pos[i][1];
//			if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size())
//				continue;
//			dfs(board, word, nx, ny, cur + 1, ret);
//		}
//		board[x][y] = ch;
//
//	}
//	bool exist(vector<vector<char>>& board, string word) {
//		if (board.size() == 0)
//			return false;
//		if (word.size() == 0)
//			return true;
//		bool ret = false;
//		for (int i = 0; i < board.size(); i++)
//		{
//			for (int j = 0; j < board[0].size(); j++)
//			{
//				if (board[i][j] == word[0])
//				{
//					ret = false;
//					dfs(board, word, i, j, 0, ret);
//					if (ret == true)
//					{
//						break;
//					}
//				}
//			}
//		}
//		return s;
//	}
//};
//int main()
//{
//	vector<vector<char>> board = {
//		{'A', 'B', 'C', 'E'},
//		{ 'S', 'F', 'C', 'S' },
//		{ 'A', 'D', 'E', 'E' }
//	};
//	string str = "ABCCED";
//	Solution s;
//	s.exist(board, str);
//	system("pause");
//}


//
//#include<vector>
//#include<algorithm>
//#include<iostream>
//using namespace std;
//
//
//int main(){
//	const int tmp[] = { -5, 7, 1, 9, -11, -12, 15 };
//	vector<int> v(&tmp[0], &tmp[sizeof(tmp) / sizeof(int)]);
//	for (int i  = 0; i  != v.size(); ++i) cout << v[i] << " ";
//	cout << "\n";
//	int cnt  = 0;//负数的个数
//	for (int i  = 0; i  != v.size(); ++i) if (v[i] < 0) ++cnt;
//	    /*开始*/
//	int positive  = 0, pos  = cnt, negative  = 0, s  = v.size(), swapTmp;
//	while (positive  != cnt && v[positive] < 0){
//		++positive;//第一个正数
//	}
//	negative  = positive;
//	while (positive  != cnt){
//		if (v[positive] >= 0){
//			while (++negative  != s && v[negative] >= 0);//positive之后的第一个负数
//			swapTmp  = v[negative];
//			v[negative] = v[pos];
//			v[pos] = v[positive];
//			v[positive] = swapTmp;
//			++pos;
//		}
//		++positive;
//	}
//	    /*结束*/
//	for (int i  = 0; i  != v.size(); ++i) cout << v[i] << " ";
//	cout << "\n";
//
//	return 0;
//}

//class ListNode
//{
//public:
//	ListNode* _prev;
//	ListNode* _next;
//	int _key;
//	int _val;
//	ListNode(int key, int val)
//		:_key(key)
//		, _val(val)
//		, _prev(nullptr)
//		, _next(nullptr)
//	{
//		
//	}
//};
//
//class DoubleList
//{
//public:
//	ListNode* tail;
//	ListNode* head;
//	int size;
//	DoubleList()
//	{
//		tail = new ListNode(-1, -1);
//		head = new ListNode(-1, -1);
//		tail->_prev = head;
//		head->_next = tail;
//		size = 0;
//	}
//
//	void addLast(ListNode* x)
//	{
//		x->_prev = tail->_prev;
//		x->_next = tail;
//		tail->_prev->_next = x;
//		tail->_prev = x;
//		size++;
//	}
//	void remove(ListNode* x)
//	{
//		x->_prev->_next = x->_next;
//		x->_next->_prev = x->_prev;
//	}
//	ListNode* removeFirst()
//	{
//		if (head->_next == tail)
//			return nullptr;
//		// head x y tail
//		ListNode* node = head->_next;
//		head->_next->_next->_prev = head;
//		head->_next = head->_next->_next;
//		return node;
//		
//	}
//	int Getsize()
//	{
//		return size;
//	}
//};
//
//#include <map>
//
//class LRUCache
//{
//public:
//	DoubleList l;
//	map<int, ListNode*> m;
//	int _capacity;
//	LRUCache(int capacity)
//	{
//		_capacity = capacity;
//	}
//	void makeRecently(int key)
//	{
//		ListNode* node = m[key];
//	
//		l.remove(node);
//		l.addLast(node);
//	}
//
//	void addRecently(int key, int val)
//	{
//		ListNode* newnode = new ListNode(key, val);
//		l.addLast(newnode);
//		m[key] = newnode;
//	}
//
//	void deletekey(int key)
//	{
//		ListNode* node = m[key];
//		l.remove(node);
//		m.erase(key);
//	}
//};



//string char_count(string str) {
//	string s;
//	for (int i = 0; i < str.size(); i++)
//	{
//		int j = i;
//		int cnt = 1;
//		while (j + 1< str.size() && str[j] == str[j + 1])
//		{
//			cnt++;
//			j++;
//		}
//		s += to_string(cnt);
//		s += str[j];
//		i = j;
//	}
//	return s;
//}


//typedef void(*handler_t)(int data);
//class MyTask   //任务类
//{
//private:
//	int _data; //处理数据
//	handler_t _handler;//处理数据的方法
//public:
//	void SetTask(int data, handler_t handler); //用户自己传入要处理的数据和方法，组织出一个任务节点
//	void Run()
//	{
//		return _handler(_data);
//	} //执行这一任务
//};

//typedef void(*handler_t)(int); // 线程的入口函数
//
//class ThreadTask
//{
//public:
//	ThreadTask()
//	{
//
//	}
//	void SetTask(int data, handler_t handler)
//	{
//		_data = data;
//		_handler = handler;
//	}
//	void Run()
//	{
//		return _handler(_data);
//	}
//	int _data;
//	handler_t _handler;
//};
//#define MAX_THREAD 10
//class ThreadPool
//{
//
//private:
//	int thr_max;
//	queue<ThreadTask> q;
//	pthread_mutex_t _mutex;
//	pthread_cond_t _cond;
//public:
//	ThreadPool(int max_ = MAX_THREAD)
//		:thr_max(max_)
//	{
//		pthread_mutex_init(&_mutex, NULL);
//		pthread_cond_init(&_cond, NULL);
//		for (int i = 0; i < thr_max; i++)
//		{
//			pthread_t tid;
//			int ret = pthread_create(&tid, NULL, thr_start, this);
//
//		}
//	}
//};
//int main()
//{
//
//	system("pause");
//}



//vector<int> v;
//void lisanhua(int x)
//{
//	auto it = lower_bound(v.begin(), v.end(), x) - v.begin();
//	if (it == v.size())
//		v.push_back(x);
//	else
//		v[it] = x;
//}
//int main()
//{
//	lisanhua(4);
//	lisanhua(4);
//	lisanhua(4);
//	lisanhua(5);
//	lisanhua(6);
//
//
//	system("pause");
//}



// 19 删除链表的倒数第k个数  建立虚拟节点，因为删除的数字可能是头结点
// 83 删除排序链表中重复元素 建立虚拟节点


//
//class Solution {
//public:
//
//	vector<int> tr;
//	int N = 0;
//	int lowbit(int x)
//	{
//		return x & -x;
//	}
//
//	void add(int x, int y)
//	{
//		for (int i = x; i <= N; i += lowbit(i))
//		{
//			tr[i] += y;
//		}
//	}
//
//	int sum(int x){
//		int sums = 0;
//		for (int i = x; i; i -= lowbit(i)){
//			sums += tr[i];
//		}
//		return sums;
//	}
//	vector<int> v;
//	void lisanhua(vector<int>& nums, int x)
//	{
//		for (int i = 0; i < nums.size(); i++)
//		{
//			auto it = lower_bound(v.begin(), v.end(), x) - v.begin();
//			if (it == v.size())
//				v.push_back(x);
//			else
//				v[it] = x;
//		}
//
//	}
//	vector<int> countSmaller(vector<int>& nums) {
//		if (nums.size() == 0)
//			return vector<int>();
//
//		int max_ = 0;
//		//sort(nums.begin(),nums.end());
//
//		for (int i = 0; i < nums.size(); i++)
//		{
//
//		}
//		vector<int> v;
//		N = nums.size();
//		return aa
//	}
//};
//
//
//class Solution {
//public:
//
//	vector<int> tmp;
//	vector<int> index;
//	vector<int> count;
//	vector<int> tmpindex;
//	void merge(vector<int>& nums, int l, int r)
//	{
//		if (l >= r)
//			return;
//		int mid = (l + r) / 2;
//		merge(nums, l, mid);
//		merge(nums, mid + 1, r);
//
//		int idx = l;
//		int ll = l;
//		int rr = mid + 1;
//		while (ll <= mid && rr <= r){
//			if (nums[index[ll]] <= nums[index[rr]])
//			{
//				
//				tmp[idx] = nums[ll];
//				count[index[ll]] += rr - mid;
//				tmpindex[idx] = index[ll];
//				idx++;
//				ll++;
//			}
//			else
//			{
//				tmpindex[idx] = index[rr];
//				tmp[idx++] = nums[rr++];
//			}
//		}
//		while (ll <= mid)
//		{
//			tmp[idx] = nums[ll];
//			tmpindex[idx] = index[ll];
//			count[index[ll]] += rr - mid;
//			ll++;
//			idx++;
//		}
//		while (rr <= mid)
//		{
//			tmpindex[idx] = index[rr];
//			tmp[idx++] = nums[rr++];
//		}
//		for (int i = l; i <= r; i++)
//		{
//			nums[i] = tmp[i];
//			index[i] = tmpindex[i];
//		}
//		
//		//for (int i = l; i <= r; i++)
//		//{
//		//	cout << nums[i] << " ";
//		//}
//		//cout << endl;
//		
//	}
//	vector<int> countSmaller(vector<int>& nums) {
//		if (nums.size() == 0)
//			return nums;
//		int n = nums.size();
//		tmpindex.resize(n);
//		tmp.resize(n);
//		index.resize(n);
//		count.resize(n);
//
//		for (int i = 0; i < n; i++)
//		{
//			index[i] = i;
//		}
//
//		merge(nums, 0, nums.size() - 1);
//		return count;
//	}
//};
//int main()
//{
//	Solution s;
//	vector<int> nums = { 5, 2, 6, 1 };
//	vector<int> v;
//	v =	s.countSmaller(nums);
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	system("pause");
//}


// 
/*

共享内存一定要加锁吗？

Linux共享内存可以不用加锁，不过需要一种机制来标记共享内存的读写状态


方法一：

1.负责写入的进程，必须知道当前共享内存是否可以写入，上一次的写入内容是否有被负责读取的进程读走
2. 负责读取的进程，必须知道当前共享内存是否需要读取，防止重复读取

简单实现：
1. 通过读写锁来控制
2. CAS

方法二：

保存两块共享内存，一块用于读操作，一块用于写操作。

初始时，两块共享内存内容一致。读操作均是读取第一块共享内存的数据；写操作均是写第二块共享内存。

在多个读操作一个写操作的情况下，读操作均从第一块共享内存读取，写操作修改第二块共享内存的数据。
直至写操作完成，交换两块共享内存的下标，即第二块共享内存用于接下来的读操作，
第一块共享内存根据第二块共享内存数据更新，用于接来下的写操作。


方法三：
实现一个FIFO的队列，生产线成不断添加一些指令到共享区域的头部加入，
消费者线程不断的从队列后面取出指令，修改共享内存上的数据


打印helloc world操作系统的动作

1. 为每一个进程分配一个唯一的进程标识符
2. 为进程分配空间
3. 初始化进程控制块
4. 操作系统将pcb加入到 维护的链表中， 就绪队列中 或者 阻塞队列中
5. 物理地址空间文件描述符和将要IO的文件对之建立联系
PCB中的file_struct结构体要与物理地址的空间文件描述符建立联系
*/