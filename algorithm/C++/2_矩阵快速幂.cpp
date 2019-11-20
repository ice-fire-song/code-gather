/** 
题目：HDU 4549 
Problem Description
M斐波那契数列F[n]是一种整数数列，它的定义如下：
F[0] = a
F[1] = b
F[n] = F[n-1] * F[n-2] (n > 1)
现在给出a, b, n，你能求出F[n]的值吗？
Input
输入包含多组测试数据
每组数据占一行，包含3个整数a, b, n(0 ≤ a, b, n ≤ 10^9)
Output
对每组测试数据请输出一个整数F[n]，由于F[n]可能很大，你只需输出F[n]%1000000007的值即可，每组数据输出一行。

解析：
写出f(2),f(3),f(4),f(5) .........可以发先 a b的系数是一系列的fib数列   如果可以求出fib数列 求快速幂就可以了    这样问题就在于如何求fib数列了
很容易想到用矩阵法
 
                     1     1
【f[n-1],f[n-2]】 *  1     0     =  【f[n],f[n-1]】
 
可知矩阵为 1 1
           1 0  
 
另外 注意在矩阵相乘的时候会溢出 要用long long    如果对1000000007求余的话 依旧会溢出 （如果对它求余就错 应该是溢出了 坑爹）   
但是可以这样做  利用下面定理
当gcd(A,M)==1的时候 
A^X = A^( X mod Eular(M) ) ( mod M ) .
 
这样我们只需对1000000006求余
 
对于本题
f(n)是斐波那契数列的第n项
F(n) = a^f(n-1)*b^f(n)
然后由费马小定理
 a^f(n-1) = a^(f(n-1)%1000000006) (mod 1000000007)
b^f(n) = b^(f(n)%1000000006) (mod 1000000007)
这2个直接快速幂就行了
f(n)%1000000006这个用矩阵快速幂可以求然后答案就出来了

**/ 
// 题解，算法来自网上 
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

