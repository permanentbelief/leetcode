#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <vector>
using namespace std;
// ����д��ֻ�����˷���ֵ������������������ݲ��Ǻ�  ����һ
/*int compress(vector<char>& chars) {
	char s[127] = { 0 };
	for (int i = 0; i < chars.size(); i++)
	{
		s[chars[i]]++;
	}
	int count1 = 0;
	int count2 = 0; //�����ж������ֲ�����0
	int count3 = 0;
	for (int i = 0; i < 127; i++)
	{
		
		if (s[i] != 0)
		{
		
			count2++;
		}
		if (s[i] >= 100)
			count2 += 3;
		else if (s[i] >= 10)
			count2 += 2;
		else if (s[i] > 1)
			count2 += 1;

	}
	return count2;
}*/

// ������  ���¿��ٵ������ֵ����ԭ����  �ռ临�Ӷ�O(N) ʱ�临�Ӷ�O(N)
int compress(vector<char>& chars) {
	
	if (chars.size() == 0)
		return  0;
	vector<char> ret;
	int count = 0;
	for (int i = 0; i < chars.size(); i++)
	{
		char temp = chars[i];
		count = 1;
		while ((i < chars.size() - 1) && (chars[i] == chars[i + 1]))
		{
			count++;
			i++;
		}
		ret.push_back(temp);
		if (count >= 10)
		{
			ret.push_back(count / 10 + '0');
			ret.push_back(count % 10 + '0');
		}
		else if (count> 1)
		{
			ret.push_back(count + '0');
		}
	}
	for (int i = 0; i < ret.size(); i++)
	{
		chars[i] = ret[i];
	}

	return ret.size();
}

int main()
{
	vector<char>str;
	str.push_back('a');
	str.push_back('a');
	str.push_back('a');
	str.push_back('a');
	str.push_back('b');
	str.push_back('b');
	str.push_back('b');
	str.push_back('b');
	//str.push_back('C');
	//str.push_back('c');

	cout << compress(str) << endl;
	system("pause");
}