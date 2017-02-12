# include <bits/stdc++.h>
using namespace std;

# define ll long long int
# define max_val 112345

void swap(ll *a,ll *b)
{
	ll temp=*a;
	*a=*b;
	*b=temp;
}

//max heap
void max_heapify(ll arr[],int index,int size)
{
	int left=2*index;
	int right=left+1;
	int largest;
	if(left <= size && arr[left] > arr[index])
	{
		largest=left;
	}
	else
	{
		largest=index;
	}
	if(right <= size && arr[right] > arr[largest])
	{
		largest=right;
	}
	if(largest != index)
	{
		swap(&arr[largest],&arr[index]);
		max_heapify(arr,largest,size);
	}
}

void build_heap(ll arr[],int size)
{
	for(int i=size/2;i>=1;--i)
	{
		max_heapify(arr,i,size);
	}
}



void heapsort(ll arr[],int N)
{
	int heap_size=N;
	build_heap(arr,N);
	
	//1 indexed array...0th element just ignored plainly
	for(int i=N;i>=2;--i)
	{
		swap(&arr[i],&arr[1]);
		heap_size--;
		max_heapify(arr,1,heap_size);	//takes O(logn)
	}
}

int main()
{
	int size;
	cin>>size;
	ll arr[max_val];
	for(int i=1;i<=size;++i)
	{
		cin>>arr[i];
	}
	heapsort(arr,size);
	for(int i=1;i<=size;++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}