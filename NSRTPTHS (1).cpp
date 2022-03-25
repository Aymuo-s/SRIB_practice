#include <iostream>
#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

vector<int> bfs(vector<int> adj[],int n,vector<int>&path)
{
    
    int dist[n+1];
    for(int i=1;i<=n;i++)
    dist[i]=INT_MAX;
    queue<int>q;
    dist[0]=0;
    path[0]=1;
    q.push(0);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(dist[node]+1<dist[it])
            {
                dist[it]=dist[node]+1;
               
                path[it]=path[node];
                
                q.push(it);
            }
            else if(dist[node]+1==dist[it])
            {
                path[it]+=path[node];
                path[it]%=1000000007;
            }
        }
    }
    return path;
}

int main() {
	// your code goes here
	int t,m,n,u,v;
	cin>>t;
	while(t--)
	{
	    
	    cin>>n>>m;
	    vector<int>adj[n+1];
	    for(int i=0;i<m;i++)
	    {
	        cin>>u>>v;
	        adj[u].push_back(v);
	        adj[v].push_back(u);
	        
	    }
	    vector<int>path(n+1,0);
	    bfs(adj,n,path);
	    for(int i=1;i<=n;i++)
           cout<<path[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
