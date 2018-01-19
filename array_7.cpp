#include<iostream>
using namespace std;
int main()
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
    while(arr[low]!=1&&low<high)
    low++;
    while(arr[high]!=0&&low<high)
    high--;
    if(arr[low]==1&&arr[high]==0)
    {
    arr[low]=0;
    arr[high]=1;
    low++;
    high--;
  }
  }
  for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
}
