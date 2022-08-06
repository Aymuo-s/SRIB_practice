/*
https://www.geeksforgeeks.org/samsung-interview-experience-set-39-campus-r-d-noida/
https://www.careercup.com/page?pid=samsung-interview-questions
A Doctor travels from a division to other division where divisions are connected like a graph(directed graph) and
the edge weights are the probabilities of the doctor going from that division to other connected division but the
doctor stays 10mins at each division now there will be given time and had to find the division in which he will be
staying by that time and is determined by finding division which has high probability.
Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division
in which he will be there, the edges starting point, end point, probability.
Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and the traveling
time is not considered and during that 10min at 10th min he will be in next division, so be careful
2
6 10 40
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
6 10 10
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
6 0.774000
3 0.700000
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<pair<int,double>> adj[],int node,double p,int time,vector<double> &prob)
{
    if(time<=0)
    {
        prob[node]+=p;
        return;
    }
    for(auto it: adj[node])
    {

        p*=it.second;
        dfs(adj,it.first,p,time-10,prob);
        p/=it.second;
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,time;
        cin>>n>>m>>time;
        vector<pair<int,double>> adj[n+1];
        vector<double>prob(n+1,0.0);
        int u,v;
        double p;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v>>p;
            adj[u].push_back({v,p});
        }
        dfs(adj,1,1,time,prob);
        double max_prob=prob[0];
        int div=0;
        for(int i=1;i<=n;i++)
            cout<<prob[i]<<" ";
        cout<<endl;
        for(int i=1;i<=n;i++)
        {

            if(prob[i]>max_prob)
                max_prob=prob[i],div=i;
        }
        cout<<div<<" "<<max_prob<<endl;

    }

    return 0;
}
