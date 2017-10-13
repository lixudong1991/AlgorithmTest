#include<stdio.h>
typedef struct Val
{
	int leftIndex;
	int rightIndex;
	int maxSum;
}Val;

Val findMaxCrossSubArr(int array[], int low, int high)
{
	int len = high - low + 1;
	int mid = low + len / 2;
	int left = -1;
	int leftMax = 0;
	int sum = 0;
	for (int i = mid - 1; i >= left; i--)
	{
		sum += array[i];
		if (leftMax < sum)
		{
			leftMax = sum;
			left = i;
		}
	}
	int right = -1;
	int rightMax = 0;
	sum = 0;
	for (int i = mid; i <= high; i++)
	{
		sum += array[i];
		if (rightMax < sum)
		{
			rightMax = sum;
			right = i;
		}
	}
	Val v = {left,right,leftMax + rightMax };
	return v;
}
/*
分治法求最大子数组问题
*/
Val findMaxSubArr(int array[],int low,int high)
{
	Val v = { -1,-1,0 };
	if (low == high)
	{
		if (array[low] > 0)
		{
			v.leftIndex = low;
			v.rightIndex = low;
			v.maxSum = array[low];
		}
		return v;
	}
	if (low > high)
	{
		return v;
	}
	int len = high - low + 1;
	int mid = low + len / 2;
	Val v0 = findMaxSubArr(array, low, mid - 1);
	Val v1 = findMaxSubArr(array, mid, high);
	Val v2 = findMaxCrossSubArr(array, low, high);
	if (v0.maxSum > v1.maxSum&&v0.maxSum > v2.maxSum)
	{
		return v0;
	}else if (v1.maxSum > v0.maxSum&&v1.maxSum > v2.maxSum){
		return v1;
	}else {
		return v2;
	}
}

int main()
{
	int a[] = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	printf("array: [\40");
	for (int i = 0; i < 15; i++)
	{
		printf("%d, ", a[i]);
	}
	printf("%d]\n", a[15]);
	Val v = findMaxSubArr(a, 0, 15);
	printf("a: %d\nb: %d\nc: %d\n", v.leftIndex, v.rightIndex, v.maxSum);
	getchar();
}
