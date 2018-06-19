#include<bits/stdc++.h>
using namespace std;
int arr[11][11];
bool isPossible(int row,int col,int n)
{
    for(int i=row-1;i>=0;i--)
    {
        if(arr[i][col]==1)
        return false;
    }
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
    {
        if(arr[i][j]==1)
        return false;
    }
    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)
    {
        if(arr[i][j]==1)
        return false;
    }
    return true;
}
bool printNqueen(int row,int n,vector<vector<int> > &v)
{
    if(row>=n)
    {
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[j][i]==1)
                ans.push_back(j+1);
            }
        }
        v.push_back(ans);
        return true;
    }
    for(int j=0;j<n;j++)
    {
        if(isPossible(row,j,n))
        {
            arr[row][j]=1;
            printNqueen(row+1,n,v);
            arr[row][j]=0;
        }
    }
    return false;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    vector<vector<int> > v;
	    int n;
	    cin>>n;
	    memset(arr,0,11*11*sizeof(int));
	    printNqueen(0,n,v);
	    if(v.size()==0)
	    cout<<"-1";
	    else
	    {
	        sort(v.begin(),v.end());

	        for(int i=0;i<v.size();i++)
	        {
	            cout<<"[";
	            for(int j=0;j<v[i].size();j++)
	            cout<<v[i][j]<<" ";
	            cout<<"] ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
