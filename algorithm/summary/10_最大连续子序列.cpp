/*
������������еĺ� ������һ�����У���ȡ���е���������������Һ���� 
*/ 
// ���װ�

#include<iostream>
using namespace std;

int main() {
   int n,a;
   cout<<"�������еĳ��ȣ�";
   while(cin>>n)
   {
   	    cout<<"��������е��������ݣ�"; 
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
        cout<<"��������еĳ��ȣ�";
    }
}
