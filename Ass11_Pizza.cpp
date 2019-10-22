#include<iostream>

using namespace std;

class Pizza
{
private:
	int front,rear;
	int q[10];
	int MAX=10;
	int id;

public:
	Pizza()
	{
		front=rear=-1;
		id=0;
	}

	bool isFull()
	{
		if((front==0)&&(rear==(MAX-1)) || (front==(rear+1)%MAX))
			return true;
		else
			return false;
	}

	bool isEmpty()
	{
		if(front==-1)
			return true;
		else
			return false;
	}

	void add_order()
	{
		if(isFull())
		{
			cout<<"\nPizza Parlor is Full.......Please wait!";
		}

		else
		{
			id++;

			if(front==-1)
			{
				front=rear=0;
			}
			
			else
			{
				rear=(rear+1)%MAX;	
			}
			
			q[rear]=id;

			cout<<"\nOrder placed Succesfully!";
		}

	}

	void serve_order()
	{
		if (isEmpty())
		{
			cout<<"\nPizza Parlor has no orders in Queue!";
		}

		else
		{
			int item=q[front];

			if(front==rear)
			{
				front=rear=-1;
			}
			else
			{
				front=(front+1)%MAX;
			}
			
			cout<<"\nOrder "<<item<<" Delivered Succesfully! Thank You!";
		}
	}

	void display_order()
	{
		cout<<"\nOrders in the queue are: \n";

		for(int i=front;i!=rear;i=(i+1)%MAX)
		{
			cout<<q[i]<<" ";
		}
		cout<<q[rear];
	}
};

int main()
{
	Pizza p;
	int ch;
	char choice;

	do
	{

	cout<<"\n******************PIZZA PARLOR*******************\n\n";
	cout<<"1.New Order\n2.Serve Order\n3.Display Orders\nEnter your choice>> ";
	cin>>ch;


		switch(ch)
		{
			case 1:
			{
				p.add_order();
				break;
			}

			case 2:
			{
				p.serve_order();
				break;
			}

			case 3:
			{
				p.display_order();
				break;
			}

		}

		cout<<"\nDo you want to continue? ";
		cin>>choice;
	}while(choice=='Y' || choice=='y');

	return 0;

}
