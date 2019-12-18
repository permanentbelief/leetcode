//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//class Solution {
//public:
//
//	int lastStoneWeight(vector<int>& stones) {
//		while (stones.size() > 1)
//		{
//			sort(stones.begin(), stones.end());//≈≈–Ú“ªœ¬
//			
//			if (stones[stones.size() - 1] == stones[stones.size() - 2])
//			{
//				stones.pop_back();
//				stones.pop_back();
//			}
//			else
//			{
//				stones[stones.size() - 2] = stones[stones.size() - 1] - stones[stones.size() - 2];
//				stones.pop_back();
//			}
//
//		}
//		if (stones.size() == 0)
//			return 0;
//		else
//			return stones[0];
//	}
//};
//int main()
//{
//	Solution s;
//	vector <int> v;
//	v.push_back(2); 
//	v.push_back(7);
//	v.push_back(4);
//	v.push_back(1);
//	v.push_back(8);
//	v.push_back(1);
//	cout << s.lastStoneWeight(v) << endl;
//	system("pause");
//}