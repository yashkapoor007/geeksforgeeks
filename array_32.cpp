#include<iostream>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;
  int T=m*n;
  int a[n][m];
  int i=0,j=0,si=0,sj=0,ei=n-1,ej=m-1;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>a[i][j];
    }
  }
  while(T--)
  {
    if(i==si)
    {
      if(j!=ej)
      cout<<a[i][j++]<<" ";
      else
      cout<<a[i++][j]<<" ";
    }
    else if(j==ej)
    {
      if(i!=ej)
      cout<<a[i++][j]<<" ";
      else
      cout<<a[i][j--]<<" ";
    }
    else if(i==ei)
    {
      if(j!=sj)
      cout<<a[i][j--]<<" ";
      else
      cout<<a[i--][j]<<" ";
    }
    else if(j==sj)
    {
      if(si+1!=i)
      cout<<a[i--][j]<<" ";
      else
      {
        cout<<a[i][j++]<<" ";
      si++;
      ei--;
      sj++;
      ej--;
      }
    }
  }
  cout<<endl;
}
