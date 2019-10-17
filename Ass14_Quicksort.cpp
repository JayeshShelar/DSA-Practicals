#include<iostream>

using namespace std;

int arr[30];
void Quicksort(int,int);

int main()
{
	int n;

	cout<<"Enter the number of students: ";
	cin>>n;
	
	cout<<"\nEnter the marks: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<"You Entered: \n";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i];
	}

	Quicksort(0,n-1);

	cout<<"\nSorted marks are: ";	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}

	return 0;
}

void Quicksort(int low,int high)
{
	int i,j,pivot,temp;

	pivot=low;
	i=low;
	j=high;

	while(i<j)
	{
		while(arr[i]<=arr[pivot] && i<high)
		{
			i++;
		}

		while(arr[j]>=arr[pivot])
		{
			j--;
		}

		if(i<j)
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}

	temp=arr[pivot];
	arr[pivot]=arr[j];
	arr[j]=temp;

	Quicksort(low,j-1);
	Quicksort(j+1,high);
}