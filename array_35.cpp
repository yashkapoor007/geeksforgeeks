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
        {
            cin>>arr[i];
        }
        int z=0,c=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=0)
            arr[z++]=arr[i];
            else
            c++;
        }
        for(int i=z;i<n;i++)
        arr[i]=0;
        for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
    }
	return 0;
}
