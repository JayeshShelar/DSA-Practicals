#include<bits/stdc++.h>

using namespace std;

class sparse
{
public:
	int s[100][100],m,n,a[100][100];
	public:
	void accept();          //to accept a matrix
	void convert();         //to convert to sparse matrix
	void displaysparse();   //to display the sparse matrix
	void transpose();       //to find the transpose of a matrix
	void operator+(sparse); //to add the two sparse matrices
	void fasttranspose();   //to find the transpose using fast transpose method
};

void sparse::accept()       //function to accept a matrix
{
	int i,j;
	cout<<"Enter the number of rows:"<<endl;
	cin>>m;
	cout<<"Enter the number of columns:"<<endl;
	cin>>n;
	cout<<"Enter the elements:"<<endl;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"Matrix is:";
	for(i=0;i<m;i++)
		{
			cout<<endl;
			for(j=0;j<n;j++)
			{
				cout<<a[i][j]<<"\t";
			}
		}
}
void sparse::convert()  //function to convert to sparse matrix
{
	cout<<endl;
	int i,j;
	s[0][0]=m;
	s[0][1]=n;
	int k=1;
	for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]!=0)
				{
					s[k][0]=i;
					s[k][1]=j;
					s[k][2]=a[i][j];
					k++;
				}
			}
		}
	s[0][2]=k-1;
}
void sparse::displaysparse()    //function to display the sparse matrix
{
	int i;
	cout<<s[0][0]<<"\t";
	cout<<s[0][1]<<"\t";
	cout<<s[0][2]<<"\t";
	cout<<endl;
	for(i=1;i<=s[0][2];i++)
	{
		cout<<s[i][0]<<"\t";
		cout<<s[i][1]<<"\t";
		cout<<s[i][2]<<"\t";
		cout<<endl;
	}
}
void sparse::transpose()        //function to find the transpose of a matrix
{
	int transpose[100][3],k=1,j,i;
	if(s[0][2]>0)
	   {
	     for(i=0;i<n;i++)
	      {
		   for(j=1;j<=s[0][2];j++)
		   {
		    if(s[j][1]==i)
		    {
			 transpose[k][0]=i;
			 transpose[k][1]=s[j][0];
			 transpose[k][2]=s[j][2];
			 k++;
		    }
		   }
	      }
	   }
	   cout<<s[0][1]<<"\t";
	   cout<<s[0][0]<<"\t";
	   cout<<s[0][2]<<"\t";
	   cout<<endl;
	   for(i=1;i<=s[0][2];i++)
	   {
	      cout<<transpose[i][0]<<"\t";
	      cout<<transpose[i][1]<<"\t";
		  cout<<transpose[i][2]<<"\t";
		  cout<<endl;
	   }
}
void sparse::operator+(sparse s1)     //operator overloading function to add the two sparse matrices
{
    int i,j,k;
	sparse s3;
		if(this->s[0][0]!=s1.s[0][0]||this->s[0][1]!=s1.s[0][1])
		{
			cout<<"The two sparse matrices cannot be added"<<endl;
		}
		else
		{
			i=1;j=1;k=1;
			while(i<=this->s[0][2] && j<=s1.s[0][2])
			{
			  if(this->s[i][0]==s1.s[j][0])
			   {
				if(this->s[i][1]==s1.s[j][1])
				{
					s3.s[k][0]=this->s[i][0];
					s3.s[k][1]=this->s[i][1];
					s3.s[k][2]=this->s[i][2]+s1.s[j][2];
					i++;
					j++;
					k++;
				}
				else if(this->s[i][1]<s1.s[j][1])
				{
					s3.s[k][0]=this->s[i][0];
					s3.s[k][1]=this->s[i][1];
					s3.s[k][2]=this->s[i][2];
					i++;
					k++;
				}
				else
				{
					s3.s[k][0]=s1.s[j][0];
					s3.s[k][1]=s1.s[j][1];
		
					s3.s[k][2]=s1.s[j][2];
					j++;
					k++;
				}
			}
			  else
			  {
				  if(this->s[i][0]<s1.s[j][0])
				  {
					  s3.s[k][0]=this->s[i][0];
					  s3.s[k][1]=this->s[i][1];
					  s3.s[k][2]=this->s[i][2];
					  i++;
					  k++;
				  }
				  else
				  {
					  s3.s[k][0]=s1.s[j][0];
					  s3.s[k][1]=s1.s[j][1];
					  s3.s[k][2]=s1.s[j][2];
					  j++;
					  k++;
				  }
			  }
		   }
			while(i<=this->s[0][2])
			{
				s3.s[k][0]=this->s[i][0];
				s3.s[k][1]=this->s[i][1];
				s3.s[k][2]=this->s[i][2];
				i++;
				k++;
			}
			while(j<=s1.s[0][2])
			{
				s3.s[k][0]=s1.s[j][0];
				s3.s[k][1]=s1.s[j][1];
				s3.s[k][2]=s1.s[j][2];
				j++;
				k++;
			}
		    cout<<"Addition of the two sparse matrices is"<<endl;
			cout<<s1.s[0][0]<<"\t";
			cout<<s1.s[0][1]<<"\t";
			cout<<k-1<<"\t";
			cout<<endl;
			for(i=1;i<k;i++)
			  {
				cout<<s3.s[i][0]<<"\t";
				cout<<s3.s[i][1]<<"\t";
				cout<<s3.s[i][2]<<"\t";
				cout<<endl;
			  }
		}
}
void sparse::fasttranspose()    //function to find the transpose using fast transpose method
{
	int p[100];
	int i,k,transpose[100][3],q[100];
	for(i=0;i<s[0][2];i++)
		{
			p[i]=0;
		}
	for(i=1;i<=s[0][2];i++)
	{
		p[s[i][1]]++;
	}
	q[0]=1;
	for(i=1;i<s[0][1];i++)
	{
		q[i]=q[i-1]+p[i-1];
	}
	for(i=1;i<=s[0][2];i++)
	{
		transpose[q[s[i][1]]][0]=s[i][1];
		transpose[q[s[i][1]]][1]=s[i][0];
		transpose[q[s[i][1]]][2]=s[i][2];
		q[s[i][1]]++;
	}
	  cout<<s[0][1]<<"\t";
	  cout<<s[0][0]<<"\t";
	  cout<<s[0][2]<<"\t";
	  cout<<endl;
	  for(k=1;k<=s[0][2];k++)
		{
		  cout<<transpose[k][0]<<"\t";
		  cout<<transpose[k][1]<<"\t";
		  cout<<transpose[k][2]<<"\t";
		  cout<<endl;
		}

}
int main()
{
	sparse o1,o2;
	cout<<"For matrix A:"<<endl;
	o1.accept();
	o1.convert();
	cout<<"The sparse matrix A is:"<<endl;
	o1.displaysparse();
	cout<<"For matrix B:"<<endl;
    o2.accept();
    o2.convert();
    cout<<"The sparse matrix B is:"<<endl;
    o2.displaysparse();
    cout<<"The transpose of sparse matrix A is:"<<endl;
    o1.transpose();
    cout<<"The transpose of sparse matrix B is:"<<endl;
    o2.transpose();
    o1+o2;
    cout<<"The fast transpose of sparse matrix A is:"<<endl;
    o1.fasttranspose();
    cout<<"The fast transpose of sparse matrix B is:"<<endl;
    o2.fasttranspose();
}