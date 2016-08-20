#include <stdio.h>

int size = 100000;

unsigned int merge_sort(int start, int end, int*arr);
unsigned int merge(int start, int mid, int end, int*arr);

int main()
{
	FILE *fp = fopen("E:\\IntegerArray.txt","r");
	int i=0;
	int test_arr[100000];
	//int test_arr[9] = {4, 2, 1, 3, 5, 8, 0, 43, 10};
	unsigned int result;

	if (fp == NULL) {
     printf("파일이 없음\n");
	}
	else
	{
		for(i = 0;i<size;i++)
		{
			fscanf(fp,"%d\n",&test_arr[i]);
		}
	}
	printf("Start\n");

	for(i=0;i<size;i++)
	{
		//printf("%d," ,test_arr[i]);
	}
	printf("\n");
	result = merge_sort(0,size-1,test_arr);

	for(i=0;i<size;i++)
	{
		//printf("%d," ,test_arr[i]);
	}
	printf("\nresult: %d\n" ,result);

	return 0;
}

unsigned int merge_sort(int start, int end, int*arr)
{
	int mid;
	unsigned int left = 0;
	unsigned int right = 0;
	unsigned int merge_num =0;

	if(start<end)
	{
		mid = (start + end)/2;
		left = merge_sort(start,mid,arr);
		right = merge_sort(mid+1,end,arr);
		merge_num = merge(start,mid,end,arr);
	}
	printf(">%d\n" ,left + right + merge_num);
	return left + right + merge_num;
}

unsigned int merge(int start, int mid, int end, int*arr)
{
	unsigned int count = 0;
	int index = start;
	int temp_arr[100000] = {0,};

	int i,j,k,m;

	i = start;
	j = mid+1;
	k = end;

	while( (i<=mid) && (j<=end) )
	{
		if(arr[i]<arr[j])
		{
			temp_arr[index] = arr[i];
			i++;
		}
		else
		{
			temp_arr[index] = arr[j];
			j++;
			count += mid-i+1;
		}

		index++;
	}

	if(i>mid)
	{
		for(m=j;m<=end;m++)
		{
			temp_arr[index++] = arr[m];
		}
	}
	else
	{
		for(m=i;m<=mid;m++)
		{
			temp_arr[index++] = arr[m];
		}
	}

	for(m=start;m<=end;m++)
	{
		arr[m] = temp_arr[m];
	}

	return count;
}