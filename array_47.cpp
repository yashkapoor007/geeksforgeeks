#include <iostream>
using namespace std;
int printNGE(int arr[],int max,int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        return arr[i];
    }
    return -1;
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
	        int max=arr[i];
	        cout<<printNGE(arr+i+1,max,n-i-1)<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
