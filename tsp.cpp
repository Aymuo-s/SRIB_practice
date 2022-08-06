/*Mr. Kim has to deliver refrigerators to N customers. From the office, he is going to visit all the customers and then return to his home.
Each location of the office, his home, and the customers is given in the form of integer coordinates (x,y) (0≤x≤100, 0≤y≤100) .
The distance between two arbitrary locations (x1, y1) and (x2, y2) is computed by |x1-x2| + |y1-y2|,
where |x| denotes the absolute value of x; for instance, |3|=|-3|=3.
The locations of the office, his home, and the customers are all distinct.
You should plan an optimal way to visit all the N customers and return to his among all the possibilities.
You are given the locations of the office, Mr. Kim’s home, and the customers; the number of the customers is in the range of 5 to 10.
Write a program that, starting at the office, finds a (the) shortest path visiting all the customers and returning to his home. Your program only have to report the distance of a (the) shortest path.
Constraints
5≤N≤10. Each location (x,y) is in a bounded grid, 0≤x≤100, 0≤y≤100, and x, y are integers.
Input
You are given 10 test cases. Each test case consists of two lines; the first line has N, the number of the customers,
and the following line enumerates the locations of the office, Mr. Kim’s home, and the customers in sequence.
Each location consists of the coordinates (x,y), which is represented by ‘x y’.
Output
Output the 10 answers in 10 lines. Each line outputs the distance of a (the) shortest path.
Each line looks like ‘#x answer’ where x is the index of a test case. ‘#x’ and ‘answer’ are separated by a space.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int ans=INT_MAX;

int x[12],y[12],n;
void fun(int pos,int total,int s, vector<int> &ds,vector<int>&visited)  //pos = previous node; i= current node
{

    if(n==total+1 && pos==1)    //visited all cities and end in home(index 1)
    {

            ans=min(ans,s);
            for(auto it: ds)
                cout<<it<<" ";
            cout<<endl;
            return;

    }


    for(int i=1;i<n;i++)
    {
        if(!visited[i])
        {
            ds.push_back(i);
            visited[i]=1;
            int sum=abs(x[pos]-x[i])+abs(y[pos]-y[i]);
            fun(i,total+1,s+sum,ds,visited);
            ds.pop_back();
            visited[i]=0;
        }
    }

}

int main()
{
    cin>>n;
    n=n+2;
    vector<int>visited(n,0);
    vector<int>ds;
    ds.push_back(0);    //start from office
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];

    visited[0]=1;
    fun(0,0,0,ds,visited);
    cout<<ans<<endl;

    return 0;
}
