//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//	bool lemonadeChange(vector<int>& bills) {
//		if (bills.empty())
//			return true;
//		int partFSum = 0;
//		int partTenSum = 0;
//		int partTWSum = 0;
//		int sum = 0;
//		for (int i = 0; i < bills.size(); i++)
//		{
//			if (bills[i] == 5)
//				partFSum += 1;
//			else if (bills[i] == 10)
//			{
//				if (partFSum == 0)
//					return false;
//				partTenSum++;
//				partFSum--;
//			}
//			else if (bills[i] == 20) //2уе10 3уе5
//			{
//				if (partFSum < 3 && ( (partFSum <1) || (partTenSum < 1)))
//				{
//					return false;
//				}
//				else
//				{
//					if (!(partFSum == 0 || partTenSum == 0))
//					{
//						partFSum -= 1;
//						partTenSum -= 1;
//						continue;
//					}
//					if (partFSum >= 3)
//					{
//						partFSum -= 3;
//						// partTWSum += 1;
//						continue;
//					}
//
//				}
//
//			}
//		}
//		return true;
//	}
//};
//int main()
//{
//	Solution s;
//	vector <int> v;
//	v.push_back(5);
//	v.push_back(5);
//	v.push_back(5);
//	v.push_back(10);
//	v.push_back(5);
//	v.push_back(5);
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(20);
//	v.push_back(20);
//	cout << s.lemonadeChange(v) << endl;
//	system("pause");
//}