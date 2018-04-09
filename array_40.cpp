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
	    int m;
	    cin>>m;
	    int wR=0,wL=0,zeros=0,bestL=0,bestWindow=0;
	    while(wR<n)
	    {
	        if(zeros<=m)
	        {
	            if(arr[wR]==0)
	            zeros++;
	            wR++;
	        }
	        if(zeros>m)
	        {
	            if(arr[wL]==0)
	            zeros--;
	            wL++;
	        }
	        if(wR-wL>bestWindow)
	        {
	            bestWindow=wR-wL;
	            bestL=wL;
	        }
	    }
	    for(int i=0;i<bestWindow;i++)
	    {
	        if(arr[bestL+i]==0)
	        cout<<bestL+i<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
