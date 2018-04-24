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
	    int c[1001]={0};
	    for(int i=0;i<n1;i++)
	    {
	        cin>>arr1[i];
	        c[arr1[i]]=1;
	    }
	    for(int i=0;i<n2;i++)
	    {
	        cin>>arr2[i];
	        if(c[arr2[i]]==1)
	        c[arr2[i]]=2;
	    }
	    int flag=0;
	    for(int i=0;i<1001;i++)
	    {
	        if(c[i]==2)
	        {cout<<i<<" ";flag=1;}
	    }
	    if(flag==0)
	    cout<<"Zero";
	    cout<<endl;
	}
	return 0;
}
