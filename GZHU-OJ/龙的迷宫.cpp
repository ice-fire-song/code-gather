#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

struct node
{
	
	int x,y,power,step;
    bool operator <(const node&other) const
	{
		if(other.step==step)return power<other.power;
		else return other.step<step;
	}
	
};

int mat[105][105],n,m;

int X[4]={0,-1,0,1};
int Y[4]={1,0,-1,0};
bool judge(int x,int y)
{
	if(x<0||x>=n||y<0||y>=m||mat[x][y]==-1)return false;
	else return true;
	
	
}



int BFS(int sx,int sy,int dx,int dy)
{
	priority_queue<node>q;
	
	node NODE;
	NODE.x=sx,NODE.y=sy,NODE.power=mat[sx][sy],NODE.step =0;
	
	q.push(NODE);
	mat[sx][sy]=-1;
	
	while(!q.empty())
	{
		node top=q.top();
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			node tt;
			
			tt.x=top.x+X[i];
			tt.y=top.y+Y[i];
			if(judge(tt.x,tt.y ))
			{
				
				tt.power=top.power+mat[tt.x ][tt.y ];
				tt.step=top.step+1;
				q.push(tt);
				
				mat[tt.x][tt.y ]=-1;
				
				if(tt.x==dx&&tt.y==dy)return tt.power;
				
			}
			
			
			
			
		}
	

		
	}
	

	return -1;

 } 



int main()
{
cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false); 
	
	int t;
	
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		
	cin>>n>>m;
		
		int sx,sy,dx,dy;
		cin>>sx>>sy>>dx>>dy;
		
		for(int x=0;x<n;x++)
		for(int y=0;y<m;y++)
	    cin>>mat[x][y];
		int dis=BFS(sx,sy,dx,dy);
		
		cout<<"Case #"<<i<<": ";
		
	    if(dis==-1)cout<<"Mission Impossible."<<endl;
	    else 	cout<<dis<<endl;
			
		
	}
	
		
} 
