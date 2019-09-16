#include<iostream>

using namespace std;

class Stack
{
private:
    char exp[20];
    int top;

public:

    Stack()
    {
        top =-1;
    }

    bool isEmpty()
    {
    	if (top==-1)
    		return true;
    	else
    		return false;
    }

    bool isFUll()
    {
    	if (top==19)
    		return true;
    	else 
    		return false;
    }

    void push(char k)
    {
        if(!isFUll())
            exp[++top]=k;
    }

    char pop()
    {
        if(!isEmpty())
            return exp[top--];
        
    }

    void check(string s)
    {
        int n=s.length();
        int i=0;

        if(s[i]=='}'|| s[i]==']'|| s[i]==')')
        {
            cout<<"Invalid expression\n";
            return;
        }

        while(i<n)
        {
            if(s[i]=='{'|| s[i]=='['|| s[i]=='(')
            {
                push(s[i]);
            }

            if(s[i]=='}'|| s[i]==']'|| s[i]==')')
            {
                if(isEmpty())
                {
                    cout<<"Number of opening brackets is less\n";
                    return;
                }

                char temp;
                temp=pop();
                if(temp=='(' && s[i]!=')' || temp=='[' && s[i]!=']'||temp=='{' && s[i]!='}')
                {
                    cout<<"Bracket error\n";
                    return;
                }
            }
            i++;
        }

        if(!isEmpty())
        {
            cout<<"Number of closing  brackets is less\n";
            return;
        } 
        else
        {
        	cout<<"\nValid Expression\n\n";
    	}
    }
};



int main()
{
    Stack s;
    cout<<"*****EXPRESSION VALIDATOR*****\n";
    char c;

    do{
        string p;
        cout<<"Enter the Expression: ";
        cin>>p;
        s.check(p);
        cout<<"Do you want to continue??\n>>";
        cin>>c;

    }while(c=='y'||c=='Y');
    
    return 0;
}