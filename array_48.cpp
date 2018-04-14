#include <iostream>
using namespace std;
void printLeader(int arr[],int maxi,int n)
{
    int max=arr[maxi];
    for(int i=maxi+1;i<n;i++)
    {
        if(max<=arr[i])
        {max=arr[i];if(arr[maxi]==arr[i])
        max=-100;break;}
    }
    if(max==arr[maxi])
    cout<<max<<" ";
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
	    printLeader(arr,i,n);
	    cout<<endl;
	}
	return 0;
}
