//  时间：2019-2-6 17：46
//  快速排序

# include <stdio.h>

void Quick_sort(int *, int, int);
int FindPos(int * a, int, int);

int main(void)
{
	int i;
	int a[7] = {-1, 10, 5, 7, 2, 25, 13};
	
	Quick_sort(a, 0, 6);
	for(i=0; i<7; ++i)
	{
		printf("%d ", a[i]);
	}
	
	return 0;
}

void Quick_sort(int * a, int low, int high)
{
	int pos;

	if(low < high)          //如果没有设置停止条件，会进入死递归
	{
		pos = FindPos(a, low, high);
	    Quick_sort(a, low, pos-1);
	    Quick_sort(a, pos+1, high);
	}
	return;
}

int FindPos(int * a, int low ,int high)
{
	int val = a[low];


	while(low < high)
	{
		while(low<high && a[high]>=val)
		{
			--high;
		}
		a[low] = a[high];
		
		while(low<high && a[low]<=val)
		{
			++low;
		}	
		a[high] = a[low];
	}
	a[low] = val;

	return low;
}