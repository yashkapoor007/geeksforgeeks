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
	    int c[20000]={0};
	    for(int i=0;i<n;i++)
	    {
	        c[arr[i]]++;
	    }
	    int count=0;
	    for(int i=0;i<n;i++)
	    {

	        if(c[arr[i]]!=0&&c[arr[i]+k]!=0&&k>0)
	        {count++;c[arr[i]]--;}
	        else if(k==0&&c[arr[i]]>1)
	        {count++;c[arr[i]]=0;}
	    }
	    cout<<count<<endl;
	}
	return 0;
}
