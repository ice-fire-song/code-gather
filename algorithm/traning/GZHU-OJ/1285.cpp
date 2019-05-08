#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);//加速作用 
    int t;
   	int n;
    cin>>t;
   
   for(int i=1;i<=t;i++)
   {
   		int num=0;
   
     	cin>>n;
   	 	string s;
   	  	getline(cin,s);//不能用getchar();
   	 
   	 	getline(cin,s);
   	 
   	 	string maxm=s;
   	 	n--;
   	 
   	    while(n--)
   	   {
   	  		getline(cin,s);
   	  		if(s.compare(maxm)>0) maxm=s;
   	  	    	else num++;
		}
   	
   	    printf("Case #%d: %d\n",i,num); 	
   	
   }
		
	
}
