#include <iostream>
#include <cmath>
using namespace std;
int printarraymissing(int arr[],int k,int n)
{
  for(int i=0;i<n;i++)
  {
    if(k==arr[i])
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
    int n;
    cin>>n;
    int m;
    cin>>m;
    int arr1[n];
    int arr2[m];
    for(int i=0;i<n;i++)
    {
      cin>>arr1[i];
    }
    for(int i=0;i<m;i++)
    {
      cin>>arr2[i];
    }
    for(int i=0;i<n;i++)
    {
  if(printarraymissing(arr2,arr1[i],m)==0)
  cout<<arr1[i]<<" ";
}
    cout<<endl;
  }
}
