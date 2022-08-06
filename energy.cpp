/*
Initially you have H amount of energy and D distance to travel. You may travel
with any of the given 5 speeds. But you may only travel in units of 1 km. For
each km distance traveled, you will spend corresponding amount of energy.
e.g. the given speeds are:
Cost of traveling 1 km: [4, 5, 2, 3, 6]
Time taken to travel 1 km: [200, 210, 230, 235, 215]
Find minimum time required to cover total D km with remaining H >= 0
1 <= H <= 4000
1 <= D <= 1000
*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int a=0,b=0,c=0,d=0,e=0;
int  ans= INT_MAX;
void solve(int dis,int H,vector<int>&cost,vector<int>&time)
{
    for(a=0;a<=dis;a++)
    {

        if(a==dis )
        {
            if(a*cost[0]<=H )
                ans=min(ans,a*time[0]);
        }
        if(a*cost[0]>H)
            break;

        for( b=0;a+b<=dis;b++)
        {
            if(a+b==dis )
            {
                if(a*cost[0]+b*cost[1]<=H )
                ans=min(ans,a*time[0]+b*time[1]);
            }
            if(a*cost[0]+b*cost[1]>H)
            break;

            for( c=0;a+b+c<=dis;c++)
            {
                if(a+b+c==dis )
                {
                if(a*cost[0]+b*cost[1]+c*cost[2]<=H )
                ans=min(ans,a*time[0]+b*time[1]+c*time[2]);
                }
                if(a*cost[0]+b*cost[1]+c*cost[2]>H)
                break;
                for( d=0;a+b+c+d<=dis;d++)
                {
                    if(a+b+c+d==dis )
                    {
                    if(a*cost[0]+b*cost[1]+c*cost[2]+d*cost[3]<=H )
                    ans=min(ans,a*time[0]+b*time[1]+c*time[2]+d*time[3]);
                    }
                    if(a*cost[0]+b*cost[1]+c*cost[2]+d*cost[3]>H)
                    break;

                    for( e=0;a+b+c+d+e<=dis;e++)
                    {

                        if(a+b+c+d+e==dis )
                        {
                        if(a*cost[0]+b*cost[1]+c*cost[2]+d*cost[3]+e*cost[4]<=H )
                        ans=min(ans,a*time[0]+b*time[1]+c*time[2]+d*time[3]+e*time[4]);
                        }
                        if(a*cost[0]+b*cost[1]+c*cost[2]+d*cost[3]+e*cost[4]>H)
                        break;

                    }
                }
            }
        }
    }
}
int main()
{
    vector<int>cost(5);
    vector<int>time(5);
    for(int i=0;i<5;i++)
        {
            cin>>cost[i];

        }
    for(int i=0;i<5;i++)
        {
            cin>>time[i];

        }
        int dis,H;
        cin>>dis>>H;
        solve(dis,H,cost,time);
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;
        cout<<ans;
        return 0;


}
