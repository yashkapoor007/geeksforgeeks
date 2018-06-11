#include<iostream>
#include<stack>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;

	while(t--)
	{
	    stack<int> s;
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    for(int i=n-1;i>=0;i--)
	    {
	        if(s.empty())
	        {
	            s.push(arr[i]);
	            arr[i]=-1;
	        }
	        else if(s.top()>arr[i])
	        {
	            int t=s.top();
	            s.push(arr[i]);
	            arr[i]=t;
	        }
	        else
	        {
	            while(!s.empty()&&arr[i]>=s.top())
	            {
	                s.pop();
	            }

	            if(s.empty())
	            {
	                s.push(arr[i]);
	                arr[i]=-1;
	            }
	            else
	            {
	                int t=s.top();

	                s.push(arr[i]);
	                arr[i]=t;
	            }
	        }
	    }
	    for(int i=0;i<n;i++)
	    cout<<arr[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
