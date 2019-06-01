//线段树：将一个区间分解为一些单元区间，每个单元区间对应线段树的每个叶子节点 

//以下程序求区间的最大值（可以通过改动其中的小部分来求最小值，区间和） 
#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
#include <queue> 
#include <vector> 
#include <algorithm> 
#include <cmath> 
#include <map> 
#include <set> 
#include <stack> 
#include <string.h> 
using namespace std;
int arr[100050],n;char a[20];
struct node
{
    int val;  //具体数值 
    int len;  //覆盖区间长度 
    int l,r;  //左右儿子 
}tree[3000001];
void build(int root,int l,int r)  //建树 
{
    int mid;
    
    tree[root].l=l;tree[root].r=r;
    if (l==r) tree[root].val=arr[l];
    else
    {
        mid=(l+r)/2;
        build(root*2,l,mid);     //递归构造左子树 
        build(root*2+1,mid+1,r); //递归构造右子树 
        tree[root].val=max(tree[root*2].val,tree[root*2+1].val);//存储左右子树的和 
    }
}
void update(int root,int id,int addval)  //单点更新 
{
    int mid;
    if (tree[root].l==tree[root].r)
    {
        tree[root].val+=addval;
        return;
    }
    else
    {
        mid=(tree[root].l+tree[root].r)/2;
        if (id<=mid) update(root*2,id,addval);
        else update(root*2+1,id,addval);
        tree[root].val=max(tree[root*2].val,tree[root*2+1].val);
    }
}
int ask(int root,int l,int r) //查询区间最大值 
{
    int mid;
    if (tree[root].l==l&&tree[root].r==r)
        return tree[root].val;
    else
    {
        mid=(tree[root].l+tree[root].r)/2;
        if (mid>=r)
            return ask(root*2,l,r);
        else if (mid<l)
            return ask(root*2+1,l,r);
        else return max(ask(root*2,l,mid),ask(root*2+1,mid+1,r));
    }
}
int main()
{
    int t,ans=1;
   scanf("%d",&t);
   while(t--)
   {
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
     scanf("%d",&arr[i]);
     build(1,1,n);
     printf("Case %d:\n",ans++);
     int ind,val;
     while(scanf("%s",&a))
     {
        if(a[0]=='E')break;
         
        scanf("%d%d",&ind,&val);
        if(a[0]=='Q') printf("%d\n",ask(1,ind,val));
        else if(a[0]=='A')update(1,ind,val);
        else if(a[0]=='S')update(1,ind,-val);
        }
   }
}
