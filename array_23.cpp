#include <iostream>
#include <cmath>
using namespace std;
int printpair(int arr[],int k,int n)
{
  int c[1001]={0};
  for(int i=0;i<n;i++)
  {
    c[arr[i]]=1;
  }
  for(int i=0;i<n;i++)
  {
    if(k-arr[i]>=0)
    if(c[k-arr[i]]==1)
    return 1;
  }
  return 0;
}
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    if(printpair(arr,k,n))
    cout<<"Yes";
    else
    cout<<"No";
    cout<<endl;
  }
}
