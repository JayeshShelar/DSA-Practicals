#include<iostream>
#include<string.h>

using namespace std;

struct Node
{
	string name;
	int prn;
	Node *next;
};

class Pinaccle
{
	public:
	Node *header;
	Node *temp;
	int m,k;
	Node *footer;
	
	Pinaccle()
	{
		header=NULL;
		k=0;
	}
	
	void InsertMember()
	{
		Node *nn=new Node;
		nn->next=NULL;
		cout<<"Enter the Name: ";
		cin>>nn->name;
		cout<<"Enter the PRN: ";
		cin>>nn->prn;
		
		if(header==NULL)
		{
			header=nn;
		}
		else
		{
			temp=header;
			
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=nn;
		}
	}
	
	void DisplayList()
	{
		temp=header;
		
		if(header==NULL)
		{
			cout<<"CLUb has no members to be delted!!";
		}
		
		else
		{
		
			cout<<"\n******PINACCLE CLUB*******\nName \tPRN ";
		
			while(temp!=NULL)
			{
				cout<<"\n"<<temp->name<<"\t"<<temp->prn;
				temp=temp->next;
			}
		}
	}

	void DeleteMember()
	{
		temp=header;
		Node *prev;
		int num;

		int a=CheckIfPresent();

		cout<<"a="<<a;
		if(a==0)
		{
			cout<<"No Members present to delete";
		}
		
		else if(a>2)
		{
			cout<<"\nEnter the prn to delete the member: ";
			cin>>num;
			temp=header;

			while(temp!=NULL && temp->prn!=num)
			{
        		prev = temp; 
        		temp = temp->next; 
			}

		    prev->next = temp->next; 
		}
		
		else if(a==2)
		{
			DeleteLast();
		}
		
		else
		{
			DeleteFirst();
		}
		
	}
	
	int CheckIfPresent()
	{
		int a=0;
		
		temp=header;
		
		while(temp!=NULL)
		{
			a++;
			temp=temp->next;
		}
		return a;
	}
	
	void Reverse()
	{
		m=CheckIfPresent();
		
		while(m!=0)
		{
			temp=header;
			for(int i=0;i<m-1;i++)
			{
				temp=temp->next;
			}

			cout<<"\n"<<temp->name<<"\t"<<temp->prn;
			--m;	
		}
	}

	void DeleteFirst()
	{
		cout<<"President of Club deleted!!";
		header=NULL;
	}

	void DeleteLast()
	{
		temp=header;
		
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		
		temp->next=NULL;
		
		cout<<"Secretary of Club Deleted!!";
	}
	
	void concatenate_lists(Pinaccle p)
	{
		temp=header;

		while(temp->next!=NULL)
		{
			temp=temp->next;
		}

		Node *temp2=p.header;

		while(temp2->next!=NULL)
		{
			temp->next=temp2;
			temp2=temp2->next;
			temp=temp->next;
		}
	}
};

int main()
{
	int ch;
	char ch2;
	
	Pinaccle p;
	
	do
	{
		cout<<"**********PINNACLE CLUB MENU********";
		cout<<"\n1.Insert Member\n2.Display Club\n3.Delete Member\n4.Reverse\n>>";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
			{
				p.InsertMember();
				break;
			}
			case 2:
			{		
				p.DisplayList();
				break;			
			}
			case 3:
			{
				p.DeleteMember();
				break;
			}
			case 4:
			{
				p.Reverse();
				break;
			}

			case 5:
			{
				Pinaccle p2;
				int n;

				cout<<"\nEnter number of nodes for second link list: ";
				cin>>n;

				for(int i=0;i<n;i++)
				{
					p2.InsertMember();
				}

				p.concatenate_lists(p2);

				break;
			}
			default:
			{
				cout<<"Wrong choice!!";
			}
		}
		
		cout<<"\nDo you want to continue??\n>>";
		cin>>ch2;
	}while(ch2=='y'||ch2=='Y');
			
	return 0;
	
}