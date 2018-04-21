#include <iostream>
#include <cstdlib>
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
    {
      cin>>arr[i];
    }
    arr[0]=arr[0]*arr[1];
    int t=arr[n-2];
    for(int i=1;i<n-1;i++)
    {
      arr[i]=(arr[i-1]/arr[i])*arr[i+1];
    }
    arr[n-1]=t*arr[n-1];
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
  }
}
