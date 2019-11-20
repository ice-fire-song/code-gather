#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<queue>
using namespace std;

const int inf=100000000;
struct node
{
	int x,y;
	int len;
	
	bool operator <(const node&other) const
	{
		return other.len<len;
	}
	
};
priority_queue<node>Q;

int X[4]={1,0,-1,0};
int Y[4]={0,1,0,-1};

char matr[600][600];

int h,w,d;

bool judge(int x,int y)
{
	if(x<=0||x>w||y<=0||y>h||matr[x][y]=='#') return false ;
	else return true;

}
void solve(int x,int y,int distence)
{
	node Node;
	Node.x=x;
	Node.y=y;
	Node.len=distence;
	Q.push(Node);
	matr[x][y]='#'; 
	
}


int BFS(int x0,int y0)
{
	node top0;
	top0.x=x0,top0.y=y0;
	 solve(x0,y0,0);
	 
	 while(!Q.empty())
	 {
	 	node top=Q.top();
	 	Q.pop();
	 	
	 	for(int i=0;i<4;i++)
	 	{
	 		
	 		int newx=top.x+X[i];
	 		int newy=top.y+Y[i];
	 		
	 		if(judge(newx,newy))
	 		{
	 			
	 			if(matr[newx][newy]=='.')
	 		    solve(newx,newy,top.len+1);
	 		    else if(matr[newx][newy]=='@') 
	 		    solve(newx,newy,top.len+d+1);
	 	
			 }
	 		if(top.x==1||top.x==w||top.y==1||top.y==h) return top.len+1;
	 		
	 
	 		
		 }
	 	

	 }
	
}


int main()
{
	
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
		
		scanf("%d%d%d",&h,&w,&d);
		int tx,ty;
		for(int y=1;y<=h;y++)
		for(int x=1;x<=w;x++)
		{
		   cin>>matr[x][y];
			if(matr[x][y]=='S')
			{
				tx=x;
				ty=y;
			
			}
				
		}
		
		
	   if(tx==1||tx==w||ty==1||ty==h) printf("1\n");
	   else 
	   {
	   		int dis=BFS(tx,ty);
	    	printf("%d\n",dis);
	        while(!Q.empty())
			Q.pop(); 
	   }	
	}
		
	
}
