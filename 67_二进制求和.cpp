//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//	string addBinary(string a, string b) {
//		string str;
//		int Size_a = a.size(); // 先保存  出错的地方
//		int Size_b = b.size();
//		reverse(a.begin(), a.end());
//		reverse(b.begin(), b.end());
//		if (a.size() < b.size())
//		{
//			for (int i = 0; i < Size_b - Size_a; i++)
//			{
//				a.push_back('0');
//			}
//		}
//		else
//		{
//			for (int i = 0; i < Size_a - Size_b; i++)
//			{
//				b.push_back('0');
//			}
//		}
//		reverse(a.begin(), a.end());
//		reverse(b.begin(), b.end());
//		int size = a.size(); 
//		int i = size-1; //第一个数是size-1
//		int next = 0;
//		int sum = 0;
//		while (i >= 0)  // 必须取到0
//		{
//			sum = (a[i] - '0') + (b[i] - '0') + next;
//			next = 0;
//			if (sum >= 2)
//			{
//				sum -= 2;
//				next = 1;
//			}
//			str += (sum + '0');
//			i--;
//		}
//		if (next == 1)
//			str += '1';
//		reverse(str.begin(), str.end());
//		return str;
//	}
//};
//
//int main()
//{
//	Solution s;
//	cout << s.addBinary("111", "1") << endl;
//	system("pause");
//
//}