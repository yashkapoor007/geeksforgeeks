#include<iostream>
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
    int pro[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    pro[0]=arr[0]*arr[1];
    pro[n-1]=arr[n-2]*arr[n-1];
    for(int i=1;i<n-1;i++)
    pro[i]=arr[i-1]*arr[i+1];
    for(int i=0;i<n;i++)
    cout<<pro[i]<<" ";
  }
}
