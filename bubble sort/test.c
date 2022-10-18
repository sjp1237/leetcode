#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

//冒牌排序
//时间复杂度为O（N^2)
//空间复杂度O(1)
void _swap(int* x, int* y) {
	int tmp = *x;
	*x =*y;
	*y=tmp;
}
void bubble_sort(int* arr, int size) {
	assert(arr);
	for (int i = size - 1; i > 0; i--) {
		for (int j = 1; j <=i; j++) {
			if (arr[j-1] > arr[j]) {
				_swap(&arr[j-1], &arr[j]);
			}
		}
	}
}

void Print(int* arr,int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
}

int main() {
	int arr[] = { 12,354,65,23,6,346,43 };
	bubble_sort(arr, sizeof(arr)/sizeof(arr[0]));
	
	Print(arr, sizeof(arr)/ sizeof(arr[0]));
	return 0;
}