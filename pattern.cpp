#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int arr[n+1][n+1];
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
    arr[i][j]=0;
    int k=0;
    int c=1;
    for(int i=1;i<=n;i++)
    {
      for(int j=i;j<=n;j++)
      {
          arr[j][j-k]=c;
          c++;
      }
      k++;
    }
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
        if(arr[i][j]!=0)
        cout<<arr[i][j]<<" ";
        cout<<endl;
        k++;
      }
    }
}
