#include<iostream>

using namespace std;

class student
{
	static int total;
	int count;
	int roll[99];
	
	public:
	student()
	{
		count=0;
	}
	
	void accept()
	{
		cout<<"\nEnter the value of count: ";
		cin>>count;
		
		if((total+count)<=60)
		{
			l1:	
			cout<<"\nNow enter the set: ";
			for(int i=0;i<count;i++)
			{
				cin>>roll[i];
				total++;
			}
			
			for(int i=0;i<count;i++)
			{
				for(int j=i+1;j<count;j++)
				{
					if(roll[i]==roll[j])
					{
						cout<<"\nThe set contains duplicate elements please re-enter the set";
						goto l1;
					}
				}
			}
		}
		
		else
		{
			cout<<"Sorry!! You cannot enter data of more than 60 students!!!!!!";
			exit(0);
		}
	}
	
	void display()
	{

		cout<<"\nThe set is: ";
		for(int i=0;i<count;i++)
		{
			cout<<roll[i]<<" ";
		}
	}
	
	void set_union(student s1,student s2)
	{
		int flag;
		
		for(int i=0;i<s1.count;i++)
		{
			roll[i]=s1.roll[i];
			count++;
		}
		
		for(int i=0;i<s2.count;i++)
		{
			flag=0;
			
			for(int j=0;j<s1.count;j++)
			{
				if(s2.roll[i]==s1.roll[j])
				{
					flag=1;
					break;
				}
			}
			
			if(flag==0)
			{
				roll[count]=s2.roll[i];
				count++;
			}
		}
		
		cout<<"\n*****Union set is:***** ";
	}
	
	void set_intersection(student s1,student s2)
	{
		int flag;
		
		for(int i=0;i<s2.count;i++)
		{
			flag=0;
			
			for(int j=0;j<s1.count;j++)
			{
				if(s2.roll[i]==s1.roll[j])
				{
					flag=1;
					break;
				}
			}
			
			if(flag==1)
			{
				roll[count]=s2.roll[i];
				count++;
			}
		}
		
		cout<<"\n*****Intersection set is:***** ";

	}

	void set_difference(student union_set,student s2)
	{
		int flag;
		
		for(int i=0;i<union_set.count;i++)
		{
			flag=0;
			
			for(int j=0;j<s2.count;j++)
			{
				if(s2.roll[j]==union_set.roll[i])
				{
					flag=1;
					break;
				}
			}
			
			if(flag==0)
			{

				roll[count]=union_set.roll[i];
				count++;

			}
		}

		cout<<"\n*****Difference set is:***** ";

	}

	void no_sports(student s)
	{
		cout<<"\n\nTotal Students who does not play any sport are: "<<60-s.count;
	}
	
};

int student::total=0;

int main()
{
	student s_cricket,s_badminton,s_union,s_intersection,s_diff_cricket,s_diff_badminton,s;
	
	s_cricket.accept();
	s_cricket.display();
	
	s_badminton.accept();
	s_badminton.display();

	s_union.set_union(s_cricket,s_badminton);
	s_union.display();
	
	s_intersection.set_intersection(s_cricket,s_badminton);
	s_intersection.display();

	s_diff_cricket.set_difference(s_union,s_cricket);
	s_diff_cricket.display();

	s_diff_badminton.set_difference(s_union,s_badminton);
	s_diff_badminton.display();
	
	s.no_sports(s_union);

	return 0;
}
