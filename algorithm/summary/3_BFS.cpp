// 以下代码应用于：岛屿问题--岛屿个数问题 
// 算法：BFS 
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
struct node
{
    int x,y;
}Node;

int n,m;
char matrix[105][105];
bool inq[105][105] = {false};
int  X[8] = {0,0,1,-1,1,1,-1,-1};
int Y[8] = {1,-1,0,0,1,-1,1,-1};
bool judge(int x,int y)
{
    if(x>=n||x<0||y>=m||y<0)
    return false;
    if(matrix[x][y]-'0'==0||inq[x][y]==true) return false ;
    return true ;
}
void BFS(int x,int y)
{
    queue<node>q;
    Node.x = x,Node.y = y;
    q.push(Node);
    inq[x][y] = true;
    while(!q.empty())
    {
        node top = q .front();
        q.pop();
        for(int i=0;i<8;i++)
        {
            int newX = top.x+X[i];
            int newY = top.y+Y[i];
            if(judge(newX,newY))
             {  
             	Node.x = newX,Node.y = newY;
            	q.push(Node);
            	inq[newX][newY] = true;
             }
        }
    }
    
}
int main()
{
    while(cin>>n>>m)
    {    
    	for(int x=0;x<n;x++)
    	for(int y=0;y<m;y++)
      		cin>>matrix[x][y];
        
    	int ans=0;
    	for(int x=0;x<n;x++)
    	for(int y=0;y<m;y++)
		{
        
        	if(matrix[x][y]-'0'==1&&inq[x][y]==false)
        	{
            	ans++;
            	BFS(x,y);
        	}
   		}
    	cout<<ans<<endl;
    	memset(matrix,'\0',sizeof(matrix));//注意，由于有多组输入数据；所以每次要进行这两步初始化
    	memset(inq,false,sizeof(inq));
	}
}
