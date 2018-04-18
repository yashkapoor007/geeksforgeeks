#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n1,n2;
	    cin>>n1>>n2;
	    int arr1[n1],arr2[n2];
	    for(int i=0;i<n1;i++)
	    cin>>arr1[i];

	    for(int i=0;i<n2;i++)
	    cin>>arr2[i];
	    if(arr1[0]>arr1[1])
	    {for(int i=n2-1;i>=0;i--)
	    {
	        int last=arr2[i];
	        if(arr1[n1-1]<last)
	        {
	            arr2[i]=arr1[n1-1];
	            int j=0;
	            while(last<arr1[j])
	            j++;
	            for(int k=n1-1;k>j;k--)
	            {
	                arr1[k]=arr1[k-1];
	            }
	            arr1[j]=last;
	        }
	    }
	    	    for(int i=0;i<=n1-1;i++)
	    cout<<arr1[i]<<" ";
	    for(int i=0;i<=n2-1;i++)
	    cout<<arr2[i]<<" ";
	    cout<<endl;}
	    else
	    {for(int i=n2-1;i>=0;i--)
	    {
	        int last=arr2[i];
	        if(arr1[n1-1]>last)
	        {
	            arr2[i]=arr1[n1-1];
	            int j=0;
	            while(last>arr1[j])
	            j++;
	            for(int k=n1-1;k>j;k--)
	            {
	                arr1[k]=arr1[k-1];
	            }
	            arr1[j]=last;
	        }
	    }
	    for(int i=n2-1;i>=0;i--)
	    cout<<arr2[i]<<" ";
	    for(int i=n1-1;i>=0;i--)
	    cout<<arr1[i]<<" ";
	    cout<<endl;}
	}
	return 0;
}
