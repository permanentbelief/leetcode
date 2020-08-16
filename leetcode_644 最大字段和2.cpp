#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		if (nums.size() < k) return false;
		double maxVal = DBL_MIN;
		double minVal = DBL_MAX;
		// 寻找最值
		for (double n : nums){
			maxVal = max(maxVal, n);
			minVal = min(minVal, n);
		}

		double err = 1e-5;
		// 用二分法查找平均值x，对于每个x去检查是否有子数组的平均值大于x
		while (maxVal - minVal > err){
			double mid = (maxVal + minVal) / 2.0;
			if (check(nums, mid, k))
				minVal = mid;
			else
				maxVal = mid;
		}
		return maxVal;
	}

private:
	// 判断数组内是否有一段长度大于等于k的子数组，满足均值大于key
	// 只需利用当前累加和，减去当前最小累加和即可判断
	// 时间复杂度O(n)
	bool check(vector<int>&nums, double key, int k){
		double sum = 0, prev = 0, minSum = 0;
		for (int i = 0; i < k; ++i)
			sum += nums[i] - key;
		if (sum >= 0)
			return true;
		for (int i = k; i < nums.size(); ++i) {
			sum += nums[i] - key;
			prev += nums[i - k] - key;
			minSum = min(prev, minSum);
			if (sum >= minSum)
				return true;
		}
		return false;
	}
};

const int N = 1000;

bool check1(vector<int>& arr, double mid, int k)
{
	double sums = 0;
	double minSum = 0;
	double prev = 0;
	for (int i = 0; i < k; i++)
	{
		sums += arr[i] - mid;
	}
	cout << sums << endl;
	if (sums >= 0)
		return  true;
	for (int i = k; i < arr.size(); i++)
	{
		sums += arr[i] - mid;
		prev += arr[i - k] - mid;
		minSum = min(minSum, prev);
		if (sums >= minSum)
			return true;
	}
	return false;
}
bool check(vector<int>&nums, double key, int k){
	double sum = 0, prev = 0, minSum = 0;
	for (int i = 0; i < k; ++i)
		sum += nums[i] - key;
	if (sum >= 0)
		return true;
	for (int i = k; i < nums.size(); ++i) {
		sum += nums[i] - key;
		prev += nums[i - k] - key;
		minSum = min(prev, minSum);
		if (sum >= minSum)
			return true;
	}
	return false;
}

double re(vector<int>& nums, int k)
{

	/*
	if(arr.size() < k)
	return false;
	double r = INT_MIN;
	double l = INT_MAX;

	int ll = INT_MIN;
	int rr = INT_MAX;
	//  cout << l << r  << endl;
	for(int n : arr)
	{
	rr = min(rr,n);
	ll = max(ll,n);
	}

	// l = ll*1.0;
	//r = rr*1.0;
	//  cout << ll << rr <<endl;
	//   cout << l << r <<endl;
	double err = 0.000001;
	// cout << err  << endl;
	while(r - l > err)
	{
	double mid = (l + r)  / 2.0;
	if(check(arr,mid,k))
	l = mid;
	else
	r = mid;
	}
	return r;
	*/
	if (nums.size() < k) return false;
	double maxVal = INT_MIN;
	double minVal = INT_MAX;
	// 寻找最值
	for (double n : nums){
		maxVal = max(maxVal, n);
		minVal = min(minVal, n);
	}

	double err = 1e-5;
	// 用二分法查找平均值x，对于每个x去检查是否有子数组的平均值大于x
	while (maxVal - minVal > err){
		double mid = (maxVal + minVal) / 2.0;
		if (check(nums, mid, k))
			minVal = mid;
		else
			maxVal = mid;
	}
	return maxVal;

}

int main()
{
	vector<int> arr = { 1, 12, -5, -6, 50, 3 };
	///Solution s;
	//cout << s.findMaxAverage(arr,5) <<endl;
	int k = 5;
	cout << re(arr, k) << endl;

}