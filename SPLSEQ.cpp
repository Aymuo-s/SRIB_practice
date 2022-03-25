#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;


int numsum(int num,int p)
{
    int r,sum=0;
    while(num)
    {
        r=num%10;
        sum+=pow(r,p);
        num=num/10;
    }
    return sum;
}

int sequence(int num,int p)
{
    unordered_map<int,int> mpp;
    int i=0;
    while(mpp.find(num)==mpp.end())
    {
        mpp[num]=i;
        num=numsum(num,p);
        i++;
        
    }
    return mpp[num];
}

int main() {
	// your code goes here
	int n,p,t;
	cin>>t;
	while(t--)
	{
	    cin>>n>>p;
	    cout<<sequence(n,p)<<endl;
	}
	return 0;
}
