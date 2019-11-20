/*
错排公式： 
  1，核心递推公式： 
    D(n) = (n-1) [D(n-2) + D(n-1)]
    特殊的：D(1) = 0, D(2) = 1
  2，简化的公式：[n!/e+0.5](e.g. e是自然对数的底，[x]表示取x的整数部分)  
*/ 

#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{
   int n;  
   while(cin>>n)
   {
        int sum=1;
        for(int i=1;i<=n;i++)
    	{
         	sum*=i;
        }
        double s=sum/exp(1)+0.5;    
        int s1= s;
        cout<<s1<<endl;
   }
}

