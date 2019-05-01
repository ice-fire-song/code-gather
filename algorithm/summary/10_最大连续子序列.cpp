/*
最大连续子序列的和 ：给定一个数列，求取其中的最大连续子序列且和最大 
*/ 
// 简易版

#include<iostream>
using namespace std;

int main() {
   int n,a;
   cout<<"输入数列的长度：";
   while(cin>>n)
   {
   	    cout<<"输入该数列的所有数据："; 
   		int max=0,sum=0;
        for(int i=0;i<n;i++)
        {
           cin>>a;
           sum=sum+a;
           if(sum>max)
           max=sum;
        
           if(sum<0)sum=0;               
        }
        cout<<max<<endl;
        cout<<"输入该数列的长度：";
    }
}
