#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
string ssh="32767",sint="2147483647",sll="9223372036854775807";
int com(string a,string b)
{
	
	int lena=a.size();
	int lenb=b.size();
	if(lena!=lenb)
	{
		if(lena<lenb)return -1;
		else return 1;
	}
	else
	{
		
		
		return a.compare(b);
		
	}
	
	
}


int main()
{
  string s;
  
  while(cin>>s)
  {
  	
  	if(s[0]=='-')
  	{
  		s.erase(0,1);
  	     string ssh1=ssh,sint1=sint,sll1=sll;
  	     ssh1[ssh1.size()-1]+=1;
  	     sint1[sint1.size()-1]+=1;
  	     sll1[sll1.size()-1]+=1;
  	
  			if(com(s,ssh1)<=0) printf("short\n");
  		else if(com(s,sint1)<=0) printf("int\n");
  		else if(com(s,sll1)<=0) printf("long long\n");
  		else printf("It is too big!\n");
  	
	  }
  	else 
  	{
  		
  		if(com(s,ssh)<=0) printf("short\n");
  		else if(com(s,sint)<=0) printf("int\n");
  		else if(com(s,sll)<=0) printf("long long\n");
  		else printf("It is too big!\n");
  		
  		
  		
  		
	  }
  	
  }
  
  
}
