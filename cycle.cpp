// print cycle in a graph in sorted order.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,int par,vector<int>adj[],vector<int>&vis,int &cy,vector<int>&path)
{
    vis[node]=1;
    path.push_back(node);
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            if(dfs(it,node,adj,vis,cy,path ))
                return true;
        }
        else
            if(par!=it)
            {
                cy=it;
                return true;
            }
    }
    return false;
}
void printcycle (vector<int> &path,int cy)
{
    cout<<"Cycle:";
    for(int j=0;j<path.size();j++)
    {

        if(path[j]==cy)
            while(j<path.size())
            {
                cout<<path[j]<<" ";
                j++;
            }
    }
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n,m,u,v;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        sort(adj[i].begin(),adj[i].end());
    vector<int>vis(n+1,0);
    int cy=-1;
    vector<int>path;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            if(dfs(i,-1,adj,vis,cy,path))
            printcycle(path,cy);
    }

    }


    return 0;
}
