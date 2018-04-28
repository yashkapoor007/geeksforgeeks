#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int minimum(int arr[],int n)
{
    int min=INT_MAX;
    for(int i=1;i<=n-1;i++)
    {
        if(arr[i]-arr[i-1]<min)
        min=arr[i]-arr[i-1];
    }
    return min;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        cout<<minimum(arr,n)<<endl;
    }
	//code
	return 0;
}
