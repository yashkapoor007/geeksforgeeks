#include <iostream>
#include <climits>
using namespace std;
void modify(int arr[],int maxi,int n)
{
    int max=INT_MIN;
    for(int i=maxi+1;i<n;i++)
    {
        if(max<arr[i])
        max=arr[i];
    }
    if(max!=INT_MIN)
    arr[maxi]=max;
    else
    arr[maxi]=-1;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    for(int i=0;i<n;i++)
	    {
	        modify(arr,i,n);
	    }
	     for(int i=0;i<n;i++)
	    {
	       cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
