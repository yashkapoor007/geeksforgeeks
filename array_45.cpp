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
	    int arr[n];int count[101]={0};
	    int maj=-1;
	    for(int i=0;i<n;i++)
	    {cin>>arr[i];count[arr[i]]++;
	        if(count[arr[i]]>n/2)
	        maj=arr[i];
	    }
	    if(maj!=-1)
	    cout<<maj<<endl;
	    else
	    cout<<"NO Majority Element\n";
	}
	return 0;
}
