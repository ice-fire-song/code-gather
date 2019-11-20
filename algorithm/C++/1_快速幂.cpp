//快速幂取模 
#include<iostream>
using namespace std;
long long mod=1000000007;
long long quick(long long k,long long n)
{
	long long sum=1;
	while(k)
	{
		n = n%mod; 
		if(k&1) sum = sum*n%mod;
		
		n = (n*n);
		k = k>>1;
	 } 
	 return sum;
}
int main()
{

    // a为底，n为幂 
	long long a,n,result;
	while(cin>>a>>n)
	{
     	result = quick(n,a);
     	cout<<result<<endl;
	}
}
