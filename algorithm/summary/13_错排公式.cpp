/*
���Ź�ʽ�� 
  1�����ĵ��ƹ�ʽ�� 
    D(n) = (n-1) [D(n-2) + D(n-1)]
    ����ģ�D(1) = 0, D(2) = 1
  2���򻯵Ĺ�ʽ��[n!/e+0.5](e.g. e����Ȼ�����ĵף�[x]��ʾȡx����������)  
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

