#include <stdio.h>
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[],int l,int h)
{
    int i,j;
    int pivot=arr[h];
    i=(l-1);
    for(j=l;j<h;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
        
    }
    swap(&arr[i+1],&arr[h]);
    return i+1;
}
void quick_sort(int arr[],int l,int h)
{
    if(l<h)
    {
        int pi;
        pi=partition(arr,l,h);
        quick_sort(arr,l,pi-1);
        quick_sort(arr,pi+1,h);
    }
}

int is_duplicate(int sum,int i,int j,int arr[],int n)
{
    int l,h;
    l=0,h=n-1;
    while(l<h)
    {
        if(l==i||l==j)
        {
            l++;continue;
        }
        if(h==i||h==j)
        {
            h--;
            continue;
        }
        if(arr[l]+arr[h]<sum)
        l++;
        else if(arr[l]+arr[h]>sum)
        h--;
        else
        return 1;
    }
    return 0;
}

int driver(int arr[],int n)
{
    int i,j,sum=0,mini=-1;
    for(i=n-1;i>0;i--)
    {
        for(j=i-1;j>=0;j--)
        {
            sum=arr[i]+arr[j];
            if(is_duplicate(sum,i,j,arr,n))
            {
                if(sum>mini)
                mini=sum;
            }
        }
    }
    return mini;
    
}


int main(void) {
	// your code goes here
	int t,n;
	int i=0;
	scanf("%d",&t);
	while(t--)
	{
	    i++;
	    scanf("%d",&n);
	    int arr[n];
	    quick_sort(arr,0,n);
	    for(int i=0;i<n;i++)
	    scanf("%d",&arr[i]);
	    quick_sort(arr,0,n);
	    printf("#%d %d\n",i,driver(arr,n));
	}
	return 0;
}

