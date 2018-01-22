#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
void printpair(int arr[],int k,int l,int r)
{
  int left=l;
  int right=r;
  int diff=INT_MAX;
  while(l<r)
  {
    if(abs(arr[l]+arr[r]-k)<diff)
    {
      left=l;
      right=r;
      diff=abs(arr[l]+arr[r]-k);
    }
    if(arr[l]+arr[r]<k)
    l++;
    else
    r--;
  }
  if(arr[left]>arr[right])
  cout<<arr[right]<<" "<<arr[left];
  else
  cout<<arr[left]<<" "<<arr[right];
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
    (printpair(arr,k,0,n-1));
    cout<<endl;
  }
}
