#include <bits/stdc++.h>
using namespace std;
bool bysec(const pair<int,int> &a,const pair<int,int> &b)
{
    if(a.first>b.first)
    return true;
    else if(a.first==b.first)
    return a.second<b.second;
    else
    return false;
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
	    int count[61]={0};
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        count[arr[i]]++;
	    }
	    vector< pair<int,int> >v;
	    for(int i=0;i<n;i++)
	    {
	        v.push_back(make_pair(count[arr[i]],arr[i]));
	    }
	    sort(v.begin(),v.end(),bysec);
	    for(int i=0;i<n;i++)
	    cout<<v[i].second<<" ";
	    cout<<endl;
	}
	return 0;
}
