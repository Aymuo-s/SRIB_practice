#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void permute(vector<int> &ds,int n,int &ans,int freq[])
{
    if(ds.size()==n)
    {
        ans++;
    }
    for(int i=1;i<=n;i++)
    {
        if(!freq[i])
        {
            if(ds.size()+1==i)
            continue;
            ds.push_back(i);
            freq[i]=1;
            permute(ds,n,ans,freq);
            freq[i]=0;
            ds.pop_back();
        }
    }
}

int driver(int n)
{
    vector<int>ds;
    int freq[n+1];
    int ans=0;
    for(int i=0;i<=n;i++)
    freq[i]=0;
    permute(ds,n,ans,freq);
    return ans;
}
int main() {
	// your code goes here
	int t,n,i=0;
	cin>>t;
	while(t--)
	{
	    i++;
	    cin>>n;
	    cout<<"#"<<i<<" "<<driver(n)<<endl;
	}
	return 0;
}
