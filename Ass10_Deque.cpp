#include<iostream>

using namespace std;

class Deque
{
private:
	int queue[10];
	int front,rear;
	int MAX=9;

public:
	Deque()
	{
		front=rear=-1;
	}

	bool isFull()
	{
		if((front==0 && rear==MAX) || (front == rear+1))
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

	void insert_front(int ele)
	{
		if(isFull())
		{
			cout<<"\nQueue is Full";
			return;
		}

		else if(front == 0)
		{
			front=MAX;
		}

		else if(front == -1)
		{
			front=rear=0;
		}

		else
		{
			front--;
		}
		queue[front]=ele;
		cout<<ele<<" inserted!";
	}

	void insert_rear(int ele)
	{
		if(isFull())
		{
			cout<<"\nQueue id Full";
			return;
		}

		else if(rear == MAX)
		{
			rear=0;
		}

		else if(front = -1)
		{
			front=rear=0;
		}

		else
		{
			rear++;
		}

		queue[rear]=ele;
		cout<<ele<<" inserted!";
	}

	void delete_front()
	{
		int ele;
		ele=queue[rear];

		if(isEmpty())
		{
			cout<<"\nQueue is Empty";
			return;
		}

		else if (front == rear)
		{
			front=rear=-1;
		}

		else if (front == MAX)
		{
			front=0;
		}

		else
		{
			front++;
		}
		cout<<ele<<" deleted!";
	}


	void delete_rear()
	{
		int ele;
		ele=queue[rear];

		if(isEmpty())
		{
			cout<<"Queue is Empty";
			return;
		}

		else if(front == rear)
		{
			front=rear=-1;
		}

		else if(rear == 0)
		{
			rear=MAX;
		}

		else
		{
			rear--;
		}
		cout<<ele<<" deleted!";
	}

	void display_queue()
	{

		for(int i=front;i!=rear;i=(i+1)%MAX)
		{
			cout<<queue[i]<<" ";
		}
		cout<<queue[rear];
	}
};

int main()
{
	Deque q;
	int ch,ele;
	char choice;

	do
	{
		cout<<"\n****************DEQUE****************";
		cout<<"\n\t1.Insert Front\n\t2.Insert Rear\n\t3.Delete Front\n\t4.Delete Rear\n\t5.Display\n>>";
		cin>>ch;

		switch(ch)
		{
			case 1:
			{
				cout<<"\nEnter the element to insert: ";
				cin>>ele;

				q.insert_front(ele);
				
				break;
			}

			case 2:
			{
				cout<<"\nEnter the element to insert: ";
				cin>>ele;

				q.insert_rear(ele);
				
				break;
			}

			case 3:
			{
				q.delete_front();
				break;
			}

			case 4:
			{
				q.delete_rear();
				break;
			}

			case 5:
			{
				q.display_queue();
				break;
			}
		}

		cout<<"\n\nDo you want to continue?\n>>";
		cin>>choice;
	
	}while(choice=='Y' || choice=='y');

	return 0;
}