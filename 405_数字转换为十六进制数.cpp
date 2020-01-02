#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <string>
#include <vector>
#include  <algorithm>


using namespace std;
class Solution {
public:
	string to_Hex(int num) //将十进制转换为16进制
	{
		string str;
		static char buf[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
		if (num == 0)
			return "0";
		while (num > 0) // 15 
		{
			str += buf[num % 16 - 1];
			num /= 16;
		}
		reverse(str.begin(), str.end());
		return str;
	}
	string toHex(int num) {
		vector<int> v(32, 0);
		string str;
		long long num1 = 0;
		if (num < 0)
		{
			num1 = 0 - num;
			//num = 0 - num;
			//二进制位 -1 在取反
			for (int i = 31; i >= 0; i--)
			{
				v[i] = num1 % 2;
				num1 = num1 /= 2;
			}
			int flag = -1;
			for (int i = 31; i >= 0; i--)
			{
				if (v[i] == 1)
				{
					flag = i;
					break;
				}
			}
			for (int i = flag; i < 32; i++)
			{
				v[i] ^= 1;
			}
			for (int i = 0; i < 32; i++)
			{
				v[i] ^= 1;
			}

		}
		else
		{
			for (int i = 31; i >= 0; i--)
			{
				v[i] = num % 2;
				num /= 2;
			}
		}

		int sum = 0;
		int k = 3;
		for (int i = 0; i < 32; i++)
		{

			sum += v[i] * pow(2, k);
			k--;
			if ((i + 1) % 4 == 0)
			{
				str += to_Hex(sum);
				sum = 0;
				k = 3;
			}
		}
		int flag = -1;
		int flag_i = 0;
		int size = str.size();
		for (int i = 0; i < str.size(); i++)
		{
			while (i < str.size() && str[i] == '0')
			{
				str.erase(i, 1);
				flag_i++;
			}
			flag = flag_i;
			break;
		}
		if (flag == size)
			return "0";
		return str;

	}
};

// 别人的代码
//class Solution {
//public:
//	string toHex(int num1) {
//		if (num1 == 0)
//			return "0";
//		string res = "";
//		string hex[16] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f" };
//		unsigned int num2 = num1;
//		while (num2 != 0)
//		{
//			res = hex[num2 % 16] + res;
//			num2 /= 16;
//		}
//		return res;
//	}
//};
//int main()
//{
//	Solution s;
//	int k = -37;
//	cout << s.toHex(k) << endl;
//	system("pause");
//}