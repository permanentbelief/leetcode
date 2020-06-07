
#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


int kthSmallest(vector<vector<int>>& matrix, int k) {
	int m = matrix.size(), n = matrix[0].size();
	int lo = matrix[0][0], hi = matrix[m - 1][n - 1];
	while (lo <= hi) {
		int cnt = 0, mid = lo + (hi - lo) / 2;
		int i = m - 1, j = 0;
		while (i >= 0 && j < n) {
			if (matrix[i][j] <= mid) {
				cnt += i + 1;
				j++;
			}
			else i--;
		}
		if (cnt < k) lo = mid + 1;
		else hi = mid - 1;
	}
	return lo;
}

bool search(vector<int>& nums, int target) {
	int l = 0, r = nums.size() - 1;
	while (l <= r){
		int mid = l + (r - l) / 2;
		if (nums[mid] == target) return true;
		//×ó°ë²¿·ÖÓÐÐò
		if (nums[mid] >= nums[l]){
			if (target<nums[mid] && target >= nums[l]) r = mid - 1;//targetÂäÔÚ×ó°ë±ß
			else l = mid + 1;
		}
		else{//ÓÒ°ë²¿·ÖÓÐÐò
			if (target>nums[mid] && target <= nums[r]) l = mid + 1;//targetÂäÔÚÓÒ°ë±ß
			else r = mid - 1;
		}
	}
	return false;
}
int main()
{
	vector<int> v = {1,3,4,5,6};
	int target = 10;
	cout << search(v, target) << endl;
	system("pause");
}