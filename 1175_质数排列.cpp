#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool IsPrime(int n)
	{
		for (int i = 2; i <= n - 1; i++)
		{
			if (n % i == 0)
				return true;
		}
		return false;
	}
	int numPrimeArrangements(int n) {
		long long a = 1e9 + 7;
		// 1 0000 0000 0
		int mod = (int)(1e9 + 7);
		if (n == 1)
			return 1;
		int prime_count = 0; //ËØÊý¸öÊý
		for (int i = 2; i <= n; i++)
		{
			if (!IsPrime(i))
				prime_count++;
		}
		int Non_count = n - prime_count;
		long long Is_ = 1;
		long long Non_ = 1;
		for (int i = 1; i <= prime_count; i++)
		{
			Is_ *= i;
			Is_ %= mod;
		}
		for (int i = 1; i <= Non_count; i++)
		{
			Non_ *= i;
			Non_ %= mod;
		}
		return ((Non_* Is_) % (mod));
	}
};
int main()
{
	Solution s;
	cout << s.numPrimeArrangements(100) << endl;
	system("pause");
}