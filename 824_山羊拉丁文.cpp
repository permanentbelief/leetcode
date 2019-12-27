//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//// yes! È«²¿AC¹ý
//class Solution{
//public:
//	string toGoatLatin(string S) {
//		string outcome;
//		string str;
//		int k = 0;
//		for (int i = 0; i < S.size(); i++)
//		{
//			str.clear();
//			while(i < S.size()&& S[i] != ' ')
//			{
//				str += S[i];
//				i++;
//			}
//		
//			if (!str.empty() && (str[0] == 'a' || str[0] == 'e' || str[0] == 'i'
//				|| str[0] == 'o' || str[0] == 'u' || str[0] == 'A' || str[0] == 'E' || str[0] == 'I' 
//				|| str[0] == 'O' || str[0] == 'U'))
//			{
//				str += "ma";
//				k++;
//			}
//			if (!str.empty() && !(str[0] == 'a' || str[0] == 'e' || str[0] == 'i'
//				|| str[0] == 'o' || str[0] == 'u' || str[0] == 'A' || str[0] == 'E' || str[0] == 'I'
//				|| str[0] == 'O' || str[0] == 'U'))
//			{
//				char temp = str.front();
//				str.erase(0, 1);
//				str += temp;
//				str += "ma";
//				k++;
//			}
//			for (int i = 0; i < k; i++)
//			{
//				str += "a";
//			}
//			while (i < S.size()&& S[i] == ' ')
//			{
//				str += S[i];
//				i++;
//			}
//			i -= 1;
//			outcome += str;
//			
//		}
//		return outcome;
//	}
//};
//int main()
//{
//	Solution s;
//	string str = s.toGoatLatin("I speak Goat Latin");
//	cout << str << endl;
//	system("pause");
//}