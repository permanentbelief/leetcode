//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <string>
//
//
//using namespace std;
//string reverseOnlyLetters(string S) {
//	//string str;
//	if (S.empty())
//		return S;
//	int start = 0;
//	int end = S.size() - 1;
//	while (start <= end)
//	{
//		if (start == end)
//			break;
//		while ((start < end) && (!(S[start] >= 'A' && S[start] <= 'Z') && !(S[start] >= 'a' && S[start] <= 'z'))) //注意这里是<号
//		{
//			start++;
//		}
//		while ((start < end) && (!(S[end] >= 'A' && S[end] <= 'Z') && !(S[end] >= 'a' && S[end] <= 'z')))
//		{
//			end--;
//		}
//		swap(S[start], S[end]);
//		start++;
//		end--;
//	}
//	return S;
//}
//int main()
//{
//	string str("7_28]");
//	cout << reverseOnlyLetters(str) << endl;
//	system("pause");
//}