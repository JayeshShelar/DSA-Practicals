#include<iostream>

using namespace std;

class Student
{
public:
	int rno;
	string name;

public:
	void add_data()
	{
		cout<<"\nEnter the roll no: ";
		cin>>rno;
		cout<<"\nEnter the name: ";
		cin>>name;
	}

	void display_data()
	{
		cout<<"\nRno: "<<rno<<"\nName: "<<name;
	}

	Student* sort(Student s[],int n)
	{
		Student temp;

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n-i;j++)
			{
				if(s[j].rno>s[j+1].rno)
				{
					temp=s[j];
					s[j]=s[j+1];
					s[j+1]=temp;
				}
			}
		}
		cout<<"\nSorted successfully!\n";
		return s;
	}
};

int main()
{
	Student s[30];
	int n;
	int ch;
	char choice;
	int flag;
	string name;
	int rno;

	cout<<"\nEnter the number of Students who attended the program: ";
	cin>>n;

	for (int i = 0; i < n; i++)
	{
		s[i].add_data();
	}

	cout<<"\nStudents who attended program are: \n";
	for (int i = 0; i < n; i++)
	{
		s[i].display_data();
	}

	do
	{
		cout<<"\n**********MENU***************";
		cout<<"\n1.Linear Search\n2.Binary Search\nEnter your Choice>> ";
		cin>>ch;

		switch(ch)
		{
			case 1:
			{
				flag=0;

				cout<<"\nEnter the name to search: ";
				cin>>name;

				for(int i=0;i<n;i++)
				{
					if(s[i].name == name)
					{
						s[i].display_data();
						flag++;
						break;
					}
				}

				if (flag==0)
				{
					cout<<"\nThis Student was absent for the program!!";
				}
				break;
			}

			case 2:
			{
				flag=0;
				//We need a sorted array for binary search.....So first sort the array of Students by Roll No
				Student s3;

				s3.sort(s,n);

				cout<<"\nEnter the Rno to search: ";
				cin>>rno;

				int low=0;
				int high=n;
				int mid=(low+high)/2;

				while(low <= high)
				{
					mid=(low+high)/2;

					if(s[mid].rno == rno)
					{
						s[mid].display_data();
						flag++;
						break;
					}

					else if(s[mid].rno > rno)
					{
						high=mid-1;
					}

					else if(s[mid].rno < rno)
					{
						low=mid+1;
					}
				}

				if (flag==0)
				{
					cout<<"\nThis Student was absent for the program!!";
				}
				
				break;
			}
		
		}

		cout<<"\nDo you want to continue?";
		cin>>choice;		

	}while(choice=='Y' || choice=='y');

	return 0;
}