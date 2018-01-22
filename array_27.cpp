#include <bits/stdc++.h>
using namespace std;
void printpair(int arr[],int l,int r)
{
  int left=l;
  int right=r;
  int diff=INT_MAX;
  while(l<r)
  {
    if(abs(arr[l]+arr[r])<diff)
    {
      left=l;
      right=r;
      diff=abs(arr[l]+arr[r]);
    }
    if(arr[l]+arr[r]<0)
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
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    sort(arr,arr+n);
    (printpair(arr,0,n-1));
    cout<<endl;
  }
}
