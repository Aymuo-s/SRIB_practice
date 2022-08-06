#include<bits/stdc++.h>
using namespace std;int result;
bool safe(int i,int j,int r,int c,vector<vector<int>> &vis)
{
    if (i>=0 and i<r and j>=0 and j<c and vis[i][j]==0)
        return true;
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        {
            int n,m,r,c,l;
            cin>>n>>m>>r>>c>>l;
            vector<vector<int>>grid(n,vector<int>(m,0));
            vector<vector<int>>vis(n,vector<int>(m,0));
            for(int i=0;i<n;i++)
                {
                    for (int j=0;j<m;j++)
                    {
                        cin>>grid[i][j];
                    }
                }
            vis[r][c]=1;
            int count=0;
            if(grid[r][c]==0)
                {
                    cout<<"0"<<endl;
                    continue;
                }
                queue<vector<int>>q;
                q.push({r,c,1});
                while(!q.empty())
                {
                        int i=q.front()[0];
                        int j=q.front()[1];
                        int d=q.front()[2];
                        q.pop();

                        count++;

                        //go up
                        if((grid[i][j]==1 || grid[i][j]==2 || grid[i][j]==4 ||grid[i][j]==7 ) and d+1<=l)
                            {
                                int ni,nj;
                                ni=i-1;nj=j;
                                if(safe(ni,nj,n,m,vis) and grid[ni][nj]!=0 and grid[ni][nj]!=3 and grid[ni][nj]!=4 and grid[ni][nj]!=7)
                                {
                                        vis[ni][nj]=1;
                                        q.push({ni,nj,d+1});

                                    }
                                }

                            //go down
                        if((grid[i][j]==1 || grid[i][j]==2 || grid[i][j]==5 || grid[i][j]==6 ) and d+1<=l)
                            {
                                int ni=i+1,nj=j;
                                if(safe(ni,nj,n,m,vis) and grid[ni][nj]!=0 and grid[ni][nj]!=3 and grid[ni][nj]!=5 and grid[ni][nj]!=6)
                                {
                                        vis[ni][nj]=1;
                                        q.push({ni,nj,d+1});
                                    }
                                }
                            //go left
                        if((grid[i][j]==1 || grid[i][j]==3 || grid[i][j]==6 ||grid[i][j]==7 ) and d+1<=l)
                            {

                                int ni=i,nj=j-1;
                                if(safe(ni,nj,n,m,vis) and grid[ni][nj]!=0 and grid[ni][nj]!=2 and grid[ni][nj]!=6 and grid[ni][nj]!=7)
                                    {
                                            vis[ni][nj]=1;
                                            q.push({ni,nj,d+1});

                                    }
                                }
                            //go right
                            if((grid[i][j]==1 || grid[i][j]==3 || grid[i][j]==4 || grid[i][j]==5 ) and d+1<=l)
                                {
                                    int ni=i,nj=j+1;
                                    if(safe(ni,nj,n,m,vis) and grid[ni][nj]!=0 and grid[ni][nj]!=2 and grid[ni][nj]!=4 and grid[ni][nj]!=5)
                                    {
                                            vis[ni][nj]=1;
                                            q.push({ni,nj,d+1});

                                    }
                                }
                }

                cout<<count<<endl;
        }
}

