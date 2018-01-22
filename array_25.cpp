#include <iostream>
#include <cmath>
using namespace std;
int printpair(int arr[],int k,int n)
{
  int co=0;
  int c[1001]={0};
  for(int i=0;i<n;i++)
  {
    c[arr[i]]++;
  }
  for(int i=0;i<n;i++)
  {
    if(c[k+arr[i]]==1)
    return 1;
  }
  return -1;
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
    int x=(printpair(arr,k,n));
    cout<<x<<endl;
  }
}
