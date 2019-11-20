#include<string.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxv=1000;
const int inf=1000000000;
int d[maxv],G[maxv][maxv];
bool vis[maxv]={false};
int n,m,s;
void dijkstra(int s)
{
    fill(d,d+maxv,inf);
    d[s]=0;
    for(int i=0;i<n;i++)
    {
        int MIN=inf,u=-1;
        for(int j=0;j<n;j++)
        {
            if(vis[j]==false&&d[j]<MIN)
            {
                u=j;
             MIN=d[j];
            }
        }
        
        if(u==-1)return ;
        vis[u]=true;
        for(int v=0;v<n;v++)
        {
            if(vis[v]==false&&G[u][v]!=inf&&d[u]+G[u][v]<d[v])
            {
                d[v]=d[u]+G[u][v];
            }
            
        }
    
        
    }
        
}
int main()
{
    int u,v,w;
    cin>>n>>m>>s;
    fill(G[0],G[0]+maxv*maxv,inf);
    
    for(int i=0;i<m;i++)
    {
        
        cin>>u>>v>>w;
        G[u][v]=w;
    }
    dijkstra(s);
    for(int i=0;i<n;i++)
    cout<<d[i]<<endl;
    
}
