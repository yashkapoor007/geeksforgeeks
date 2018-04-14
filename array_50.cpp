#include <bits/stdc++.h>
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
	    cin>>arr[i];
	    int max=INT_MIN;
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	        if(max<sum)
	        max=sum;
	        if(sum<0)
	        sum=0;
	    }
	    cout<<max<<endl;
	}
	return 0;
}
