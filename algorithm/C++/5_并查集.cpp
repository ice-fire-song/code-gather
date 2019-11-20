//题目：畅通工程 来源：http://acm.hdu.edu.cn/showproblem.php?pid=1232
#include<stdio.h>  
int num[1010];  
int f(int a)  
{  
    return num[a]==a?a:f(num[a]);  
}  
  
int main()  
{  
    int i,x,y,a,b,m,n;  
    while(~scanf("%d",&n),n)  
    {  

        scanf("%d",&m);  
        for(i=1;i<=n;i++)  
        num[i]=i;  
        for(i=1;i<=m;i++)  
        {  
 
            scanf("%d%d",&a,&b);  
            x=f(a);  
            y=f(b);  
            if(x!=y)  
            num[x]=y;  
        }  
 
        int answer=0;  
        for(i=1;i<=n;i++)  
        {  
            if(num[i]==i)  answer++;  
            
        }  

        printf("%d\n",--answer);  
    }  
    return 0;  

}  

// 广大OJ  1418题
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
int a[1000010];
int find(int x)
{
return x==a[x]?a[x]=x:a[x]=find(a[x]);
}
int main()
{
    int n,q,ind;
    int ans=1;
    while(~scanf("%d%d",&n,&q))
    {
        for(int i=1;i<=n;i++)
        a[i]=i;
        printf("Case #%d:\n",ans++);
        for(int i=1;i<=q;i++)
        {
            scanf("%d",&ind);
            int res=find(ind);
            if(res==1)
            {
                puts("1");
                a[res]=n;
                a[ind]=n;
            }
            else
            {
                printf("%d\n",res);
                a[res]=res-1;
                a[ind]=res-1;
            }
        }
    }
} 

