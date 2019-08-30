#include<iostream>

using namespace std;

class Student
{
	public:
	int roll[100],n,marks[100];
	char attendance[100];
	
	public:
		
	void get_data()
	{
		cout<<"\nEnter the number of students: ";
		cin>>n;

		for(int i=0;i<n;i++)
		{
			roll[i]=i+1;
			cout<<"\nEnter the attendence for roll no."<<roll[i]<<" ";
			cin>>attendance[i];
		
			if(attendance[i]=='p')
			{
				cout<<"\nEnter the marks for roll no."<<roll[i]<<": ";
				cin>>marks[i];	
			}
			else
			{
				marks[i]=-1;
			}
		}
	}
	
	void display_data()
	{
		cout<<"\n\n*********ALL STUDENTS*********";
		cout<<"\nRoll No.\tAttendance\tMarks";
		
		for(int i=0;i<n;i++)
		{
			cout<<"\n"<<roll[i]<<"\t\t"<<attendance[i]<<"\t\t"<<marks[i];	
		}
	}
	
	void average()
	{
		int present=0;
		int total=0;
		
		float average;
		
		for(int i=0;i<n;i++)
		{
			if(attendance[i]=='p')
			{
				present++;
				total=total+marks[i];
			}
		}
		
		cout<<"\n\n*********AVERAGE*********";
		cout<<"\nPresent Students are: "<<present;
		
		average=total/present;
		
		cout<<"\nAVERAGE MARKS: "<<average;
	}
	
	void max_min()
	{
		int max=0;
		int min=99;
		
		for(int i=0;i<n;i++)
		{
			if(attendance[i]=='p')
			{
				if(marks[i]>max)
				{
				max=marks[i];
				}
				
				if(marks[i]<min)
				{
				min=marks[i];
				}
			}
		}
		cout<<"\n\n*********MAX AND MIN*********";
		cout<<"\nMAX is: "<<max;
		cout<<"\nMIN is: "<<min;
	}
	
	void display_absent()
	{
		cout<<"\n\n*********ABSENT STUDENTS*********";
		cout<<"\nRoll No.\tAttendance\tMarks";
		for(int i=0;i<n;i++)
		{
			if(attendance[i]=='a')
			{
			cout<<"\n"<<roll[i]<<"\t\t"<<attendance[i]<<"\t\t"<<marks[i];
			}
		}
	}
	
	void most_marks()
	{
		int arr[10];
		int m=0;
		int k=0;
		
		for(int i=0;i<10;i++)
		{
			arr[i]=0;
		}
		
		for(int i=0;i<n;i++)
		{
			int temp=marks[i]/10;
			arr[temp]++;
		}
				
		for(int i=0;i<10;i++)
		{						
			if(arr[i]>m)
			{
				m=arr[i];
                		k=i;
			}
		}
		cout<<"\n\n*********MOST MARKS OBTAINED*********";
		cout<<"\nMARKS SCORED BY MOST STUDENTS: "<<k*10<<"-"<<(k*10)+10;
		
	}
		
};

int main()
{
	Student s;
	s.get_data();
	s.display_data();
	s.average();
	s.max_min();
	s.display_absent();
	s.most_marks();
	return 0;
}
