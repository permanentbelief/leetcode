#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int getMaxRepetitions(string s1, int n1, string s2, int n2)
{
	int len1 = s1.size();
	int len2 = s2.size();

	int index2 = 0;
	//s2循环了几次
	int loopTimesOnS2 = 0;
	for (int i = 0; i < n1; i++)
	{
		for (int index1 = 0; index1 < len1; index1++)
		{
			if (s1[index1] == s2[index2])
			{
				index2++;
			}
			if (index2 == len2)
			{
				index2 = 0;
				loopTimesOnS2++;
			}
		}
	
	}
	return loopTimesOnS2 / n2;
}

int getMaxRepetitions1(string s1, int n1, string s2, int n2)
{
	int count1 = 0;
	int count2 = 0;
	int len1 = s1.size();
	int len2 = s2.size();

	int i = 0;
	int j = 0;
	while (count1 < n1)
	{
		if (s1[i] == s2[j])
		{
			i++;
			j++;
			if (j == len2)
			{
				count2++;
				j = 0;
			}
		}
		else
		{
			i++;
		}
		if (i == len1)
		{
			count1++;
			i = 0;
		}
	}
	return count2 / n2;
}
int main()
{
	
	system("pause");
}