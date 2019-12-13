#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int bitwiseComplement(int N) {
		int n = 32;
		int k = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (N > pow(2, i) && N < pow(2, i + 1))
			{
				k = i + 1;
				break;
			}
		}
		vector<int> v(k, 0);
		for (int i = 0; i < k; i++)
		{
			if (N % 2 == 1)
				v[i] = 0;
			else
				v[i] = 1;

			N /= 2;
		}
		reverse(v.begin(), v.end());
		int sum = 0;
		for (int i = 1; i < k; i++) //k 3λ
		{
			sum += v[i-1]* pow(2, k - i);
		}
		sum += v[k-1];
		return sum;
	}
};

int main()
{
	Solution s;
	cout << s.bitwiseComplement(0) << endl; // 1110
	system("pause");
}