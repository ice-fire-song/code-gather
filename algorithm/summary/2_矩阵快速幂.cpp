/** 
��Ŀ��HDU 4549 
Problem Description
M쳲���������F[n]��һ���������У����Ķ������£�
F[0] = a
F[1] = b
F[n] = F[n-1] * F[n-2] (n > 1)
���ڸ���a, b, n���������F[n]��ֵ��
Input
������������������
ÿ������ռһ�У�����3������a, b, n(0 �� a, b, n �� 10^9)
Output
��ÿ��������������һ������F[n]������F[n]���ܴܺ���ֻ�����F[n]%1000000007��ֵ���ɣ�ÿ���������һ�С�

������
д��f(2),f(3),f(4),f(5) .........���Է��� a b��ϵ����һϵ�е�fib����   ����������fib���� ������ݾͿ�����    ������������������fib������
�������뵽�þ���
 
                     1     1
��f[n-1],f[n-2]�� *  1     0     =  ��f[n],f[n-1]��
 
��֪����Ϊ 1 1
           1 0  
 
���� ע���ھ�����˵�ʱ������ Ҫ��long long    �����1000000007����Ļ� ���ɻ���� �������������ʹ� Ӧ��������� �ӵ���   
���ǿ���������  �������涨��
��gcd(A,M)==1��ʱ�� 
A^X = A^( X mod Eular(M) ) ( mod M ) .
 
��������ֻ���1000000006����
 
���ڱ���
f(n)��쳲��������еĵ�n��
F(n) = a^f(n-1)*b^f(n)
Ȼ���ɷ���С����
 a^f(n-1) = a^(f(n-1)%1000000006) (mod 1000000007)
b^f(n) = b^(f(n)%1000000006) (mod 1000000007)
��2��ֱ�ӿ����ݾ�����
f(n)%1000000006����þ�������ݿ�����Ȼ��𰸾ͳ�����

**/ 
// ��⣬�㷨�������� 
#include<stdio.h>  
#include<iostream>
#include<string.h>
using namespace std;
typedef long long ll ;
#define N 2  
#define mod  1000000007  
struct mat  
{  
    ll mar[N][N];  
};  
mat a,b,c,init,temp;  
mat res=
      {  
          1,0,  
          0,1  
      };  
mat mul(mat a1,mat b1)  
{  
    int i,j,l;  
    mat c1;  
    for (i=0;i<N;i++)  
    {  
        for (j=0;j<N;j++)  
        {  
            c1.mar[i][j]=0;  
            for (l=0;l<N;l++)  
            {  
                c1.mar[i][j]=c1.mar[i][j]+a1.mar[i][l]*b1.mar[l][j]%(mod-1);   
                c1.mar[i][j]%=(mod-1);  
            }  
        }  
    }  
    return c1;  
}  
mat er_fun(mat e,int x)  
{  
    mat tp;  
    tp=e;  
    e=res;  
    while(x)  
    {  
        if(x&1)  
            e=mul(e,tp);   
        tp=mul(tp,tp);  
        x>>=1;  
    }  
    return e;  
}  
ll quick_mod(ll aa,ll bb)  
{  
    ll ans=1;  
   
    while(bb)  
    {  
     aa%=mod;  
        if(bb&1)  
        {  
            ans=ans*aa%mod;  
        }  
        bb>>=1;  
        aa=aa*aa;  
    }  
    return ans;  
}  
int main()  
{  
      int n,aa,bb,cnt=0;  
      ll anum,bnum;  
      while(scanf("%d %d %d",&aa,&bb,&n)!=EOF)  
      {   
            init.mar[0][0]=1;init.mar[0][1]=1;init.mar[1][0]=1;init.mar[1][1]=0;  
             a=init;  
             if(n==0)  
             {  
                 printf("%d\n",aa);  
                 continue;  
             }  
             b=er_fun(a,n-1);  
             bnum=b.mar[0][0];  anum=b.mar[1][0];  
         
             anum=quick_mod((ll)aa,anum);bnum=quick_mod((ll)bb,bnum);  
            
             printf("%lld\n",anum*bnum%mod);  
      }  
      return 0;  
}  

