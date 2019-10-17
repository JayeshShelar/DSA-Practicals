#include<iostream>
#include <string.h>

using namespace std;

class String_operations
{
	public:

	void string_copy()
	{
		string str1,str2;

		cout<<"Enter the first string: ";
		cin>>str1;
		str2=str1;
		cout<<"The new string is: "<<str2;
	}

	void string_concatenate()
	{
		string str1,str2;
		int i=0,j=0;

		cout<<"Enter the first string: ";
		cin>>str1;
		cout<<"Enter the second string: ";
		cin>>str2;

		int l1=str1.length();
		int l2=str2.length();
		

		char str3[100];

		for(i=0;i<l1;i++)
		{
			str3[i]=str1[i];
			cout<<str3[i];
		}

		for(j=0;j<l2;j++)
		{
			str3[i+j]=str2[j];
			cout<<str3[i+j];
		}

		cout<<"The concatenated string is: "<<str3<<"\n";
	}

	void substring()
	{
	    char s[100],sub[50];
	    int i,j,c=0;
	    printf("Enter main string: ");
	    cin>>s;
	    printf("Enter the substring: ");
	    cin>>sub;

	    i=0;
	    j=0;

	    while(s[i]!='\0')
	    {
	        if(s[i]!=sub[j])
	        {
	            i++;
	        }
	        else if(s[i]==sub[j])
	        {
	            while(sub[j]!='\0')
	            {
	                if(s[i]==sub[j])
	                {
	                    i++;
	                    j++;
	                    c++;
	                }
	                else
	                {
	                    c=0;
	                    break;
	                }
	            }
	        }
	    }
	     if(c!=0)
		     printf("Substring  is present!!\n");
	     else
	    	 printf("Substring  is absent!! \n");  
	}

	void string_equality()
	{
		string str1,str2;
		int flag=0;

		cout<<"Enter the first string: ";
		cin>>str1;
		cout<<"Enter the second string: ";
		cin>>str2;

		if(str1.length()!=str2.length())
		{
			cout<<"Strings are not equal!!";
			return;
		}
		else
		{
			for(int i=0;i<str1.length();i++)
			{
				if(str1[i]!=str2[i])
				{
					cout<<"Strings are not equal!!";
					flag++;
					break;
				}
			}
			if(flag==0)
				cout<<"Strings are equal!!";
			else
				cout<<"Strings are not equal!!";
		}
	}

	void string_reverse()
	{
		string str;

		cout<<"Enter the string to reverse: ";
		cin>>str;
		
		int len=str.length()/2+1;
		char temp;

		for(int i=0;i<len-1;i++)
		{
			temp=str[i];
			str[i]=str[str.length()-i-1];
			str[str.length()-i-1]=temp;
		}
		cout<<"Reversed string is: "<<str;
	}

	void string_len()
	{
		string str;
		cout<<"Enter the string: ";
		cin>>str;
		int i=0;

		while(str[i]!='\0')
		{
			i++;
		}

		cout<<"Length of string is: "<<i;
	}
};

int main()
{
	String_operations s;
	int ch;
	char ch2;

	do
	{
		cout<<"******STRING OPERATION*********";
		cout<<"\n1.String Copy\n2.String Concatenate\n3.Check SubString\n4.String Equality\n5.String Reverse\n6.String Length";
		cout<<"\nEnter your choice: ";
		cin>>ch;

		switch(ch)
		{
			case 1:
			{
				s.string_copy();
				break;
			}
			case 2:
			{
				s.string_concatenate();
				break;
			}
			case 3:
			{
				s.substring();
				break;
			}
			case 4:
			{
				s.string_equality();
				break;
			}
			case 5:
			{
				s.string_reverse();
				break;
			}
			case 6:
			{
				s.string_len();
				break;
			}
			default:
			{
				cout<<"Wrong choice!!";
				break;
			}			
		}
		cout<<"\nDo you want to continue???\n>>";
		cin>>ch2;

	}while(ch2=='Y'||ch2=='y');

	return 0;
}