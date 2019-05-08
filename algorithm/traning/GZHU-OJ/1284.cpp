#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
const double pi=acos(-1.0);
const double g=9.8;
int main()
{
	
	int cas;
	scanf("%d",&cas);
	int ans=1;
	while(cas--)
	{
		int v,d;
		scanf("%d%d",&v,&d);
		double tmp=(d*g)/(v*v);
		if(fabs(tmp-1)<1.0e-6) tmp=1;
		
		double al=asin(tmp);
		al/=2.0;
		al=al*180/pi;
				 
        printf("Case #%d: %.7lf\n",ans++,al);
		
				
	}
	
		
}
