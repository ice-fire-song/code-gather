#include<iostream>
#include<stdio.h>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
	
	int k,n;	
	while(~scanf("%d%d",&k,&n))
	{
	
		if(k!=10)
		{
			string s;
			cin>>s;
			int len=s.size();
			int sum=0;
			for(int i=len-1;i>=0;i--)
			{
				
				sum=sum+(s[i]-'0')*pow(k,len-1-i); 
				
			}
			printf("%d\n",sum);
			
		}
		else 
		{
			int ss;
			cin>>ss;
		    int  b[1000];
       		int j=0;
   		do
     	{
        	b[j++] = ss%n;
        	ss/=n;
     	} while (ss);
		for(int i=j-1;i>=0;i--)
			printf("%d",b[i]);
		printf("\n");
						
		}
				
	}
		
}
