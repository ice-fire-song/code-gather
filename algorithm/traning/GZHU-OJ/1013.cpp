#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
    	int a[5010];
    	int work[5010]={1};
    
    	for(int i=0;i<n;i++)       
        {
        		scanf("%d",&a[i]);
        	
		}
         int maxm=0;
         for(int i=1;i<n;i++)
         {
         	work[i]=1;
         	for(int j=i-1;j>=0;--j)
         	{
         		if(a[j]<=a[i]&&work[j]>=work[i]) work[i]=work[j]+1;
         		
			 }
         	
         	if(work[i]>maxm) maxm=work[i];
		 }
         
         
    	printf("%d\n",n-maxm);
	}
}
