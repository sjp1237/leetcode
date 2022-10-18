#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


void _quicksort(vector<int>& nums, int start, int end) {
	if (start >= end)return;
	int left = start, right = end;
	int tmp = nums[start];
	while (left < right) {
		while (left < right && nums[right] > tmp) {
			right--;
		}
		while (left < right && nums[left] <= tmp) {
			left++;
		}
		swap(nums[left], nums[right]);
	}

	swap(nums[start], nums[left]);
	_quicksort(nums, start, left - 1);
	_quicksort(nums, left+1, end);

}

void quicksort(vector<int>& nums) {
	_quicksort(nums, 0, nums.size()-1);
}


int main() {

	vector<int> nums = { 1,2,345,65,23,541,23,12 };
	quicksort(nums);
	for (auto& i : nums) {
		cout << i << " ";
	}

}