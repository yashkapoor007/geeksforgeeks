#include <iostream>
#include <set>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    set<char> s;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<arr[i].length();j++)
	        {
	            s.insert(arr[i][j]);
	        }
	    }
	    set<char> ::iterator itr;
	    for(itr=s.begin();itr!=s.end();itr++)
	    {
	        cout<<*itr<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
