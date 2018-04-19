#include <iostream>
using namespace std;
void swap(int &i,int &j)
{
    int t=i;
    i=j;
    j=t;
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
	    for(int i=0;i<n-1;i++)
	    {
	        if(i%2==0)
	        {
	            if(arr[i]>arr[i+1])
	            swap(arr[i],arr[i+1]);
	        }
	        else
	        {
	            if(arr[i]<arr[i+1])
	            swap(arr[i],arr[i+1]);
	        }
	    }
	    for(int i=0;i<n;i++)
	    cout<<arr[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
