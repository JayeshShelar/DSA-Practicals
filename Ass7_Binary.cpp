#include<iostream>

using namespace std;

struct node
{
	int data;
	node *next;
	node *prev;
};

class Doubly
{
public:
	node *hn;

public:
	Doubly()
	{
		hn=NULL;
	}

	void insert()
	{
		node *nn;
		char ch;

		do
		{
			nn=new node;
			nn->next=NULL;
			nn->prev=NULL;

			cout<<"Enter data: ";
			cin>>nn->data;

			if(hn==NULL)
			{
				hn=nn;
			}
			else
			{
				node *cn;
				cn=hn;

				while(cn->next!=NULL)
				{
					cn=cn->next;
				}
				cn->next=nn;
				nn->prev=cn;
			}

			cout<<"Do you want to enter more bits:\n>>";
			cin>>ch;
		}while(ch=='Y'||ch=='y');
		
	}

	void display()
	{
		node *cn;
		cn=hn;

		if(hn==NULL)
		{
			cout<<"Empty";
		}
		else
		{
			while(cn!=NULL)
			{
				cout<<cn->data<<" ";
				cn=cn->next;
			}
		}
	}

	void ones_complement(Doubly b)
	{
		node *cn=b.hn;

		if(cn==NULL)
		{
			cout<<"Empty";
		}
		else
		{
			while(cn!=NULL)
			{
				node *nn=new node;
				nn->next=NULL;
				nn->prev=NULL;

				if(cn->data==0)
				{
					nn->data=1;
				}
				else
				{
					nn->data=0;
				}

				if(hn==NULL)
				{
					hn=nn;
				}
				else
				{
					node *cn2=hn;

					while(cn2->next!=NULL)
					{
						cn2=cn2->next;
					}
					cn2->next=nn;
					nn->prev=cn2;
				}

				cn=cn->next;

			}
		}
	}

	void twos_complement(Doubly d)
	{
		node *cn=d.hn;
		int carry=1;

		while(cn->next!=NULL)
		{
			cn=cn->next;
		}

		while(cn!=NULL)
		{
			node *nn=new node;
			nn->next=NULL;
			nn->prev=NULL;

			if(cn->data==1 && carry==1)
			{
				nn->data=0;
				carry=1;
			}
			else if((cn->data==1 && carry==0) || (cn->data==0 && carry==1))
			{
				nn->data=1;
				carry=0;
			}
			else
			{
				nn->data=0;
				carry=0;
			}

			if(hn==NULL)
			{
				hn=nn;
			}
			else
			{
				hn->prev=nn;
				nn->next=hn;
				hn=nn;
			}

			cn=cn->prev;
		}
		if(carry==1)
		{
			node *nn=new node;
			nn->next=NULL;
			nn->prev=NULL;

			nn->data=1;

			hn->prev=nn;
			nn->next=hn;
			hn=nn;
		}
	}

	void add(Doubly b1,Doubly b2)
	{
		int sum=0,carry=0;

		node *cn1=b1.hn;
		node *cn2=b2.hn;

		while(cn1->next!=NULL)
		{
			cn1=cn1->next;
		}

		while(cn2->next!=NULL)
		{
			cn2=cn2->next;
		}

		while(cn1!=NULL && cn2!=NULL)
		{
			node *nn=new node;
			nn->next=NULL;
			nn->prev=NULL;

			sum=(cn1->data+cn2->data+carry)%2;
			carry=(cn1->data+cn2->data+carry)/2;

			nn->data=sum;

			if(hn==NULL)
			{
				hn=nn;
			}
			else
			{
				hn->prev=nn;
				nn->next=hn;
				hn=nn;
			}

			cn1=cn1->prev;
			cn2=cn2->prev;
		}

		while(cn1!=NULL)
		{
			node *nn=new node;
			nn->next=NULL;
			nn->prev=NULL;

			sum=(cn1->data+carry)%2;
			carry=(cn1->data+carry)/2;

			nn->data=sum;

			if(hn==NULL)
			{
				hn=nn;
			}
			else
			{
				nn->next=hn;
				hn->prev=nn;
				hn=nn;
			}
			cn1=cn1->prev;
		}

		while(cn2!=NULL)
		{
			node *nn=new node;
			nn->next=NULL;
			nn->prev=NULL;

			sum=(cn2->data+carry)%2;
			carry=(cn2->data+carry)/2;

			nn->data=sum;

			if(hn==NULL)
			{
				hn=nn;
			}
			else
			{
				cout<<"hhhhhhh";
				nn->next=hn;
				hn->prev=nn;
				hn=nn;
			}
			cn2=cn2->prev;
		}

		if(carry==1)
		{
			node *nn=new node;
			nn->next=NULL;
			nn->prev=NULL;

			nn->data=1;

			if(hn==NULL)
			{
				hn=nn;
			}
			else
			{
				cout<<"tttttttttt";
				nn->next=hn;
				hn->prev=nn;
				hn=nn;
			}
		}
	}


};
int main()
{
	Doubly d1,d2,d3,d4,d5,d6,d7,d8;
	int ch;
	char choice;

	do
	{
		cout<<"\n\n***************BINARY OPERATIONS***************\n\n";
		cout<<"1.Ones complement\n2.Twos complement\n3.Addition\n>>";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
			{
				cout<<"\nEnter the number for Ones complement: ";
				d1.insert();
				d2.ones_complement(d1);

				cout<<"Ones complement of ";
				d1.display();
				cout<<" is ";
				d2.display();

				break;
			}

			case 2:
			{
				cout<<"\nEnter the number for Ones complement: ";
				d3.insert();
				d4.ones_complement(d3);
				d5.twos_complement(d4);

				cout<<"Twos complement of ";
				d3.display();
				cout<<" is ";
				d5.display();
				
				break;
			}

			case 3:
			{
				cout<<"\nEnter 1st Number: ";
				d6.insert();

				cout<<"\nEnter 2nd Number: ";
				d7.insert();

				d8.add(d6,d7);
				cout<<"\nAddition is: ";
				d8.display();

				break;
			}	

		}

		cout<<"\nDo you want to continue?\n>>";
		cin>>choice;

	}while(choice=='Y' || choice=='y');
	
	return 0;
}
