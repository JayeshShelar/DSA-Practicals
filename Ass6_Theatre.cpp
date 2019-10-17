#include<iostream>

using namespace std;

struct node
{
	char status;
	node *next;
	node *prev;
};

class Cinemax
{
public:
	node *hn[10];	
public:
	Cinemax()
	{
		for(int i=0;i<10;i++)
		{
			hn[i]=NULL;
		}
	}
	
	void create()
	{
		node *cn;
		
		for(int i=0;i<10;i++)	
		{
			for(int j=0;j<7;j++)
			{
				node *nn;
				nn=new node;
				
				nn->status='A';
				nn->next=NULL;
				nn->prev=NULL;
				
				if(hn[i]==NULL)
				{
					hn[i]=nn;
					//hn[i]->next=hn[i];
					//hn[i]->prev=hn[i];
				}
				else
				{
					hn[i]->prev=nn;
					nn->next=hn[i];
					//nn->prev=hn[i];
					//hn[i]->next=nn;
					hn[i]=nn;
				}
			}
			
		}
	}
	
	void display()
	{
		node *cn;
		
		cout<<"\n************CINEMAX SEAT STATUS**************\n\n";
			
		for(int i=0;i<10;i++)
		{
			cn=hn[i];	
			
			for(int j=0;j<7;j++)
			{
					cout<<cn->status<<" ";
					cn=cn->next;
			}
			cout<<"\n";
		}
	}
		
	void book()
	{
		int row,seat;
		
		cout<<"\n*************BOOKING SECTION***********\n\n";
		cout<<"Enter the row number to book: ";
		cin>>row;
		cout<<"\nEnter the seat number to book: ";
		cin>>seat; 
		
		node *cn;
		cn=hn[row-1];
		
		for(int i=0;i<seat-1;i++)
		{	
			cn=cn->next;
		}
		
		if(cn->status=='A')
		{
			cn->status='B';
			cout<<"\nSeat Booked Successfully!!!!";		
		}
		else
		{
			cout<<"\nSeat is already Booked! Try another one!";
		}
	}
	
	void cancel()
	{
		int row,seat;
		
		cout<<"\n*************BOOKING CANCELLATION SECTION***********\n\n";
		cout<<"Enter the row number to cancel: ";
		cin>>row;
		cout<<"\nEnter the seat number to cancel: ";
		cin>>seat; 
		
		node *cn;
		cn=hn[row-1];
		
		for(int i=0;i<seat-1;i++)
		{	
			cn=cn->next;
		}
		
		if(cn->status=='B')
		{
			cn->status='A';
			cout<<"\nBooking Cancelled Successfully!!!!";		
		}
	}
};

int main()
{
	Cinemax c;
	c.create();
	
	char choice;
	int ch;
	
	do
	{
		cout<<"\n************** MAIN MENU CINEMAX ***************\n\n";
		cout<<"1.Display Status\n2.Book Ticket\n3.Cancel Ticket\n>>";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
			{
				c.display();
				break;
			}
			case 2:
			{
				c.book();
				break;
			}
			case 3:
			{
				c.cancel();
				break;
			}
			default:
			{
				cout<<"\nWrong choice!";
			}
		}
		
		cout<<"\nDo you want to continue? Enter Y\n>>";
		cin>>choice;
	
	}while(choice=='Y'|| choice=='y');
	
	return 0;
}
