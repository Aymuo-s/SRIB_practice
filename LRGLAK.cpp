#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>> &g,int r,int c, vector<vector<int>> &vis)
{
    
    int dr[]={-1,-1,-1,0,1,1,1,0};
    int dc[]={-1,0,1,1,1,0,-1,-1};
    int i,count=0,newr,newc;
    vis[r][c]=1;
    count++;
    
    for(i=0;i<8;i++)
    {
        newr=r+dr[i];
        newc=c+dc[i];
        if(newr<0||newc<0||newr>=g.size()||newc>=g[0].size()||vis[newr][newc]||g[newr][newc]==0)
        continue;
        count+=dfs(g,newr,newc,vis);
    }
    return count;
    
}
int driver (vector<vector<int>>g,int r,int c)
{
    int i,j;
    int len,max_len=0;
    vector<vector<int>> vis(r,vector<int> (c,0));
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(g[i][j]==1 && !vis[i][j])
            len=dfs(g,i,j,vis);
            //cout<<len<<" ";
            if(len>max_len)
            max_len=len;
        }
    }
    return max_len;
}
int main() {
	// your code goes here
	int t,r,c,i,j,n=0;
	cin>>t;
	while(t--)
	{
	    cin>>r>>c;
	    vector<vector<int>>g(r,vector<int>(c));
	    for(i=0;i<r;i++)
	    for(j=0;j<c;j++)
	    {
	        cin>>g[i][j];
	        
	    }
	    n++;
	    int x=driver(g,r,c);
	    cout<<"#"<<n<<" "<<x<<endl;
	}
	return 0;
}
