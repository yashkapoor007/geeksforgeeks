#include <iostream>
#include <algorithm>
using namespace std;

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
	    {
	        cin>>arr[i];
	    }
	    int flag=0;
	    sort(arr,arr+n);
	    for(int i=0;i<n;i++)
	    {

	    }
	    if(flag==1)
	    cout<<"Yes\n";
	    else
	    cout<<"No\n";
	}
	return 0;
}
