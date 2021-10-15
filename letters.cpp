#include<iostream>
using namespace std;
char n[6]={'f','l','a','m','e','s'};
char t[6];


/*maintotemp*/

void maintotemp(int e,int nax)
{
	int i,j=0;
	for(i =e; i<6; i++)
	{	
		if(n[i]!='\0')		//to make sure that empty space not transfered
		{
			t[j]=n[i];
			j++;
		}
		
		if(j!=nax-1 && i==nax-1)	//changing value of i to transfer the lefted front-off elements
		{
			i=-1;
		}
		
		if(i==e-1)					//breaking the loop if the all elements are transfered exept n[e-1]
		{
			break;
		}
	}
	
	n[nax-1]='\0';
}

/*temptomain*/

void temptomain(int e,int nax)
{
	int i,j=0;
	
	for(i=e; i<6; i++)
	{
		if(i==e&&j==nax-1)
		{
			break;			//breaking if there is only one element
		}
		
		if(t[i]!='\0')
		{
			n[j]=t[i];		//changing the elements to another array 
			j++;
		}
		
	if(i==e-1)
		{
			break;
		}
		
		if(i==nax-1)
		{
			if(j!=nax-1)
			{
			i=-1;
			}
		}
	}
	
	t[nax-1]='\0';
}

/*main function*/

int main()
{
	int max=6,num,d;
	int r=0,c;
	char ans;
	
	cout<<"\nENTER THE NUMBER =";
	cin>>num;
	
	do
	{
		r++;			//for know the number of iteration
		
		c=r%2;			//checking for odd or even iteration if (even-array n to array t) (odd-array t to array n)
		
		if(num>max&&num%max!=0)
		{
			d=num%max;				//to reduce the given number less than maximum element in array
		}
		
		else if(num<max)
		{
			d=num;					//if the given number is already less than maximum no.of element in a array 
		}
		
		else if(num==max||num%max==0)
		{
			if(c==1)
			{
				
				for(int m=0; m<max; m++)
				{
					t[m]=n[m];        //eliminating last element
				}
				
				t[max-1]='\0';
				
			}
			
			else if(c==0)
			{
				
				for(int m=0; m<max; m++)
				{
					n[m]=t[m];
				}
				
				n[max-1]='\0';
			}
			goto label;					//skipping calling functions
		}
		
		if(c==1)
		{
			maintotemp(d,max);
		}
		
		else if(c==0)
		{
			temptomain(d,max);
		}
		
		label:
			max--;				//reducing maximum number by 1
			
	}while(max!=1);
	
	ans=toupper(t[0]);
	
	cout<<"\n the value  =\t"<<ans;
	
}
