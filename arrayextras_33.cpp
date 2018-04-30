#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int l=s.length();
	    int arr[l];
	    for(int i=0;i<l;i++)
	    arr[i]=int(s[i]-'0');
	    sort(arr,arr+l,greater<int>());
	    int mine=l-1;
	    for(int i=l-1;i>=0;i--)
	    {
	        if(arr[i]%2==0)
	        {
	            mi=i;
	            break;
	        }
	    }
	    int t=arr[l-1];
	    arr[l-1]=arr[mi];
	    arr[mi]=t;
	    sort(arr,arr+l-1,greater<int>());
	    for(int i=0;i<l;i++)
	    cout<<arr[i];
	    cout<<endl;
	}
	return 0;
}
