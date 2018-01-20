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
  int arr[n];
  for(int i=0;i<n;i++)
  cin>>arr[i];
  int low=0;
  int high=n-1;
  while(low<high)
  {
    while(arr[low]%2!=1&&low<high)
    low++;
    while(arr[high]&2!=0&&low<high)
    high--;
    if(arr[low]%2==1&&arr[high]%2==0)
    {
      int temp=arr[low];
    arr[low]=arr[high];
    arr[high]=temp;
  }
  low++;
  high--;
  }
  int i=0;
  while(arr[i]%2==0)
  i++;
  if(i>0)
  sort(arr,arr+i);
  sort(arr+i,arr+n);
  for(int j=0;j<n;j++)
  cout<<arr[j]<<" ";
  cout<<endl;
}
}
