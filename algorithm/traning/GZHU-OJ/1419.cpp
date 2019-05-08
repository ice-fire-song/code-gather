Subsequence
Time Limit: 2000/1000 MS (Java/Others) Memory Limit: 128000/64000 KB (Java/Others) 
SubmitStatistic Next Problem 
Problem Description
A sequence of N positive integers (10 < N < 100 000), each of them less than or equal 10000,
 and a positive integer S (S < 100 000 000) are given. Write a program to find the minimal 
length of the subsequence of consecutive elements of the sequence, the sum of which is
 greater than or equal to S.

意思：在序列中找大于或等于S的最短序列和序列的长度
算法 

#include<iostream>
#include<string.h>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxm=100000;
int sum[maxm+22];


int main()
{
	
	int cas,n,s;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d%d",&n,&s);
		
		scanf("%d",&sum[0]);
		for(int i=1;i<n;i++)
		{
			scanf("%d",&sum[i]);
			sum[i]=sum[i]+sum[i-1];
		
		}
		
		if(sum[n-1]<s) 
		{
			printf("0\n");
			continue;
		}
		
		int ans=n;
		for(int i=n-1;i>=0;i--)
		{
			if(sum[i]<s)break;
			int pos=upper_bound(sum,sum+n,sum[i]-s)-sum;
			ans=min(ans,i-pos+1);
		
		}
		
		printf("%d\n",ans);
		
	} 
	
	
	
		
}
