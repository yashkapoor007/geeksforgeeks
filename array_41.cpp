#include <iostream>
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
	    int k;
	    cin>>k;
	    for(int i=0;i<n;i++)
	    {
	       int c=0;
	        for(int j=0;j<n;j++)
	        {
	            if(j!=i)
	            {
	                if(arr[i]>=arr[j])
	                c++;
	            }
	        }
	        if(k-1==c)
	        {
	            cout<<arr[i]<<endl;
	            break;
	        }
	    }
	}
	return 0;
}
