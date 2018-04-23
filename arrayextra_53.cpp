#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n1,n2,n3;
	    cin>>n1>>n2>>n3;
	    int arr1[n1],arr2[n2],arr3[n3],c[1001]={0};
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
	        else
	        continue;
	    }
	    for(int i=0;i<n3;i++)
	    {
	        cin>>arr3[i];
	        if(c[arr3[i]]==2)
	        c[arr3[i]]=3;
	    }
	    int flag=0;
	    for(int i=0;i<1001;i++)
	    {
	        if(c[i]>=3)
	        {cout<<i<<" ";flag=1;}
	    }
	    if(flag==0)
	    cout<<"-1";
	    cout<<endl;
	}
	return 0;
}
