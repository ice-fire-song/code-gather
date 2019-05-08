#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
string ss="0123456789ABCDEFGHIJ";

bool judge(int n,int t)
{
	int f=0;
	char b[400];;
	do
	{
		b[f++]=n%t;
		n/=t;
				
	}while(n);
	
	for(int i=0;i<f;i++)
	{
		if(b[i]!=b[f-1-i]) return false;
		
		
	}
	return true;
}
void get(int n,int t)
{
	
    int a[300];
	int f=0;
	do
	{
	   int ind=n%t;
	   a[f]=ind;
	   n=n/t;
	   f++;
	}while(n);
	for(int i=f-1;i>=0;i--)
	  cout<<ss[a[i]];	
}



int main()
{
	
       int t;
       while(~scanf("%d",&t))
       {
       	 for(int i=1;i<=300;i++)
       	 {
       	 	
       	 	int number=i*i;
       	 	if(judge(number,t))
       	 	{
       	 		
       	 	  get(i,t);
       	 	  printf(" ");
			  get(number,t);
			  printf("\n");
			  
			}
           	 	     	 	
		}
                   	         	
   }
		
	
}
