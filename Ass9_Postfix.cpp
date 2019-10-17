#include <iostream>

using namespace std;

class post
{
	char expr[20]="";
	char out[20]="";
	char stack[15];
	int stack1[15];
	int top=-1,j=0;

public:
	
	void getdata()
	{
		cout<<"\n enter infix expression:";
		cin>>expr;
	}

	int getprecedence(char ch)
	{
		if(ch=='+' || ch=='-')
			return 1;
		if(ch=='*' || ch=='/')
				return 2;
		else
			return 0;
	}
	void push(char ch)
	{
		stack[++top]=ch;
	}

	char pop()
	{
		return stack[top--];
	}

	void push_int(int ch)
	{
		stack1[++top]=ch;
	}

	int pop_int()
	{
		return stack1[top--];
	}

	void evaluate()
	{
		int i=0;
		int op1=0,op2=0;
		while(out[i]!='\0')
		{
			if(out[i]=='+')
			{
				op2=pop_int();
				op1=pop_int();
				push_int(op1+op2);
			}
			else if(out[i]=='-')
			{
				op2=pop_int();
							op1=pop_int();
							push_int(op1-op2);
			}
			else if(out[i]=='*')
				{
					op2=pop_int();
					op1=pop_int();
					push_int(op1*op2);
				}
			else if(out[i]=='/')
				{
					op2=pop_int();
					op1=pop_int();
					push_int(op1/op2);
				}
			else
			{
				push_int((int)out[i]- 48);
			}
			i++;
		}
		cout<<"\n\n evaluation is:"<<pop_int()<<"\n";
	}

	int stempty()
	{
		if(top==-1)
			return 1;
		else
			return 0;
	}

	void postfix()
	{
		int i=0;
		char tmp;
		while(expr[i]!='\0')
		{
			if(expr[i]=='('|| expr[i]=='[' || expr[i]=='{')
			{
				push(expr[i]);
			}
			else if(expr[i]==')'|| expr[i]==']' || expr[i]=='}')
			{
				if(expr[i]==')')
				{
					while(stack[top]!='(')
					{
						out[j++]=pop();
					}
				}
				if(expr[i]==']')
				{
					while(stack[top]!='[')
					{
						out[j++]=pop();
					}
				}
				if(expr[i]=='}')
				{
					while(stack[top]!='{')
									{
										out[j++]=pop();
									}
				}
				tmp=pop();
			}
			else if(expr[i]=='+' || expr[i]=='-'|| expr[i]=='*' || expr[i]=='/')
			{
				if(getprecedence(stack[top])>= getprecedence(expr[i]))
				{
					out[j++]=pop();
					push(expr[i]);
				}
				else
				{
					push(expr[i]);
				}
			}
			else
			{
				out[j++]=expr[i];
			}
			i++;

		}
		if(top!=-1)
		{
			while(top>=-1){
				out[j++]=pop();
			}
		}
		out[j]='\0';
		cout<<"\n post fix expression is:";
		for(i=0;out[i]!='\0';i++)
			cout<<out[i];
	}

};

int main()
{
	post o1;
	o1.getdata();
	o1.postfix();
	o1.evaluate();
	return 0;
}
