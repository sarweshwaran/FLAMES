#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

//declaring arrays to store names

char name1[20];
char name2[20];

//creating class to find the letter in flames

class flames
{
	char n[6]={'f','l','a','m','e','s'};
	char t[6];
	void maintotemp(int e,int nax);
	void temptomain(int e,int nax);
	public :
		void find(int num);
};


//defining member functions

/*maintotemp*/

void flames::maintotemp(int e,int nax)
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

void flames::temptomain(int e,int nax)
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


///find letter in flames
void flames::find(int num)
{
	int max=6,d;
	int r=0,c;
	char ans;
	
	
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
void chk(int a);	//to get the final result

// main function 
int main()
{
	int sum=0;
	
	int n,m,total,num,a=0,x=0;
	
	char same[10];				//array to store same letters in both names
	
	//getting names
	
	cout<<"\nENTER NAME 1 :";
	gets(name1);
	
	cout<<"\nENTER NAME 2 :";
	gets(name2);
	
	n=strlen(name1);			//getting the string length
	
	m=strlen(name2);
	
	total=n+m;					//calculating the total length of the two names
	
	for(int i=0;i<=n;i++)
	{
		
		for(int j=0;j<=m;j++)
		{
			
			if(name1[i]==name2[j])						//checking for same letters
			{
				
				if(name1[i]!='\0'||name2[j]!='\0')		//making sure that empty space is not taken in count
				{
					
					name2[j]='0';				//to avoid multiple time couting the same letter in name2
					
					name1[i]='0';
					
					sum++;						//storing that how many number of letters are same			
					
					break;						//to avoid multiple time couting the same letter in name1
				}
			}
		}
	}
	
	
	cout<<"\n NUMBER OF COMMON LETTERS = "<<sum;
	
	num=total-(sum*2);								/*subracting no.of same letter(*2 because the letter was removed only  from name2)  
													   from total length of the two names.i.e, total */
													   
	
	cout<<"\n total balance letters :"<<num;		//num taken in the game as input to find a specific the letter in the word  flames
	
	chk(num);										//passing num as the argument to find the letter in the word  flames
	
}


//defining chk function


void chk(int a)
{
	
	if(a==3||a==5||a==14||a==16||a==18||a==21||a==23||a==32||a==34||a==35)
	{
		cout<<"\n\tRESULT\n\nF - \tFRIENDS";
	}
	
	else if(a==10||a==19||a==36||a==37||a==39)
	{
		cout<<"\n\tRESULT\n\nL - \tLOVE";
	}
	
	else if(a==8||a==12||a==13||a==17||a==28||a==30)
	{
		cout<<"\n\tRESULT\n\nA - \tAFFECTION";
	}
	
	else if(a==6||a==11||a==26||a==31||a==33)
	{
		cout<<"\n\tRESULT\n\nM - \tMAIRRAGE";
	}
	
	else if(a==2||a==4||a==7||a==9||a==15||a==20||a==22||a==24||a==25)
	{
		cout<<"\n\tRESULT\n\nE - \tENIMIES";
	}
	
	else if(a==1||a==27||a==29||a==38||a==40)
	{
		cout<<"\n\tRESULT\n\nS - \tSISTER";
			
	}
}
