//#define _CRT_SECURE_NO_WARNINGS 1 

//class Solution {
//public:
//	string countAndSay(int n) {
//		string s = "1";
//		for (int i = 1; i < n; i++)  //ע�⣡���� ����=n �Ƕ�n-1�� ��һ������������
//		{
//			string temp;
//			int ans = 1;  // ansһ��ʼ���ǵ���1 ��Ϊ���������ֵĴ�������1
//			for (int j = 0; j < s.size(); j++)
//
//			if (s[j + 1] == s[j]) //s[j+1]��ʲô����  Խ����
//			{
//				ans++;
//			}
//			else
//			{
//				temp += ans + '0';
//				temp += s[j];
//				ans = 1; // Ҫ��1������һ�ε���û���ظ�����
//			}
//			s = temp;
//		}
//		return s;
//	}
//
//};
/*Solution s;
	cout << s.countAndSay(2) << endl;
	cout << endl;*/


//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	string s("abcde");
//	s[s.size()] = 'A';
//	for (int i = 0; i <= s.size(); i++)
//	{
//		cout << s[i] << endl;
//	}
//	s[s.size() + 1] = 'A';
//
//
//	system("pause");
//}