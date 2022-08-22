#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"


//��������
void InsterSort(int* a, int n)
{
	//�������д�0-1��Ҫ��������ݴ�n-1
	for (int i = 0; i < n - 1; i++)
	{
		int end=i;
		int tmp =a[end+1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}	
		}
		a[end + 1] = tmp;
	}
}


void Sort(int* a, int left, int right)
{
	int keyi = a[left];
	int prev = a[left];
	int cur = a[left+1];
	while (cur <= right )
	{
		if (a[cur] < a[keyi])
		{
			prev++;
			int tmp = a[cur];
			a[cur] = a[prev];
			a[prev] = tmp;
		}
			cur++;
	}
}

//��������
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[mid] > a[left] && a[mid] < a[right] ||
		a[mid] > a[right] && a[mid] < a[left])
		return right;
	else if (a[left] > a[mid] && a[left]<a[right] || a[left]>a[right] && a[left] < a[mid])
		return left;
	else
		return mid;

}
void swap(int* s1, int* s2)
{
	int tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}


int  PartSort(int* a,int begin,int end)
{
	int keyi = GetMidIndex(a,begin,end);
	int left = begin;
	int right = end;
	while (left < right)
	{
		while (left<right&&a[right] >= a[keyi])
		{
			--right;
		}
		while (left<right&&a[left] <= a[keyi])
		{
			++left;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[left], &a[keyi]);
	return left;
}

void QuickSort(int*a,int begin,int end)
{
	if (begin >= end)
		return;
	int keyi = PartSort(a, begin, end);
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}


//ð������
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int i = 0;
		for (int j = 0; j < n-i-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
				i = 1;
			}
		}
		if (i == 0)
			break;
	}
}


//�鲢����
void _Merge(int* a,int* tmp, int begin1, int end1, int begin2, int end2)
{
	int i = begin1;
	//�ȶ���j����Ȼj������forѭ������Ͳ�����ʼ��begin1
	int j = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1++];
		else
			tmp[i++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	while (begin2 <= end2)
		tmp[i++] = a[begin2++];
	for (; j <= end2; j++)
	{
		a[j] = tmp[j];
	}
}
//�ݹ��
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	_Merge(a, tmp, left, mid, mid + 1, right);
	
}

//�ǵݹ��
void MergeSort1(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	int gap = 1;
	//���gap����n/2,С��n����Ϊ���һ�ι鲢
	while (gap <n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1, begin2 = i + gap, end2 = i + (2 * gap) - 1;
			//�����һ��С��鲢ʱ���ڶ���С���䲽���ڣ����ߵ�һ��С���䲻��gap��������Ҫ�ٹ鲢
			if (begin2 > n)
				break;
			//�����һ��С��鲢ʱ����һ��С������ڣ��ڶ���С���䲻��gap��
			if (end2 >= n-1)
				end2 = n-1 ;
			_Merge(a, tmp, begin1, end1, begin2, end2);
		}
		gap *= 2;
	}


}


void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	_MergeSort(a, 0, n-1 , tmp);
}


void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//ϣ������
void ShellSort(int* a, int n)
{
	//gap>1ΪԤ����
	//gap=1ʱΪ��������
	    int gap=n;
		while (gap > 1)//���ܵ���1
		{
			//���n=6���������3Ϊ2��2��ȥ����3Ϊ0���൱��û����������gap��+1
			gap = gap / 3 +1;
			for (int i = 0; i < n - gap; i++)
			{
				int end = i;
				int tmp = a[end + gap];
				//��������
				//������һ���������飬Ȼ���һ���������ȥ
				while (end >= 0)
				{
					if (a[end] > tmp)
					{
						swap(&a[end], &a[end + gap]);
						end -= gap;
					}
					else
						break;
				}
				a[end + gap] = tmp;
			}
		}
}


x

void AdjustDown(int* a, int parent,int n)
{
	int child = 2 * parent + 1;
	while (child <= n-1)
	{
		if (child + 1<=n-1 && a[child] < a[child + 1])
			child = child + 1;
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		
		else
		{
			break;
		}
	}
}


void Stacksort(int* a, int n)
{
	for (int i = (n- 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, i, n);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		end--;
		AdjustDown(a, 0, end+1);
	}
}










