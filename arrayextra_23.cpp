#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int r,c;
	    cin>>r>>c;
	    int arr[r][c];
	    int co[r]={0};
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
	            cin>>arr[i][j];
	            if(arr[i][j]==1)
	            co[i]++;
	        }
	    }
	    int maxi=-1,max=-1;
	    for(int i=0;i<r;i++)
	    {
	        if(co[i]>max)
	        {
	            max=co[i];
	            maxi=i;
	        }
	    }
	    cout<<maxi<<endl;
	}
	return 0;
}
