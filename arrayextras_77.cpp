#include<iostream>
#include<climits>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    int sum=0;
	    int minsum=INT_MAX;
	    for(int i=0;i<k;i++)
	    sum+=arr[i];
	    int si=0;
	    int mins;
	    if(sum<minsum)
	    {
	        minsum=sum;
	        mins=si;
	    }
	    for(int i=k;i<n;i++)
	    {
	        sum-=arr[si];
	        sum+=arr[i];
	        si++;
	        if(sum<minsum)
	        {
	            minsum=sum;
	            mins=si;
	        }
	    }
	    cout<<mins+1<<" "<<mins+k<<endl;
	}
	return 0;
}
