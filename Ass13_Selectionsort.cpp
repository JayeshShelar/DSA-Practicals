#include<iostream>

using namespace std;

void selection_sort(int arr[],int n)
{
	int temp;
	int min;

	for(int i=0;i<n;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
}

int main()
{
	int arr[60];
	int n;

	cout<<"Enter the number of students: ";
	cin>>n;

	cout<<"Enter marks of students: \n";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<"\nYou entered: \n";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}

	selection_sort(arr,n);

	cout<<"\nAfter Sorting: \n";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}

	cout<<"\nTop five scores are: \n";
	for(int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}

}