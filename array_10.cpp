#include<iostream>
using namespace std;
int maxdifarr(int arr[],int n)
{
  int maxdif=arr[1]-arr[0];
  int min=arr[0];
  for(int i=1;i<n;i++)
  {
    
    if(arr[i]-min>maxdif)
    maxdif=arr[i]-min;
    if(min>arr[i])
    min=arr[i];
  }
  return maxdif;
}
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
    int maxdif=maxdifarr(arr,n);
    cout<<maxdif<<endl;
  }
}
