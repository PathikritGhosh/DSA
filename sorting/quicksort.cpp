# include <bits/stdc++.h>
using namespace std;

#define max_val 112345

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int arr[],int start,int end)
{
	int pivot=arr[end];
	int fptr,lptr;
	fptr=start;
	lptr=start;
	for(int i=start;i<end;++i)
	{
		if(arr[i] < pivot)
		{
			swap(&arr[i],&arr[fptr]);
			fptr++;
		}
		lptr++;
	}
	swap(&arr[end],&arr[fptr]);
	return fptr;
}

void quicksort(int arr[],int start,int end)
{
	if(start < end)
	{
		int tpart=partition(arr,start,end);
		quicksort(arr,start,tpart-1);
		quicksort(arr,tpart+1,end);
	}
}

int main()
{
	int size;
	cin>>size;
	int arr[max_val];
	for(int i=0;i<size;++i)
	{
		cin>>arr[i];
	}
	quicksort(arr,0,size-1);
	for(int i=0;i<size;++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}