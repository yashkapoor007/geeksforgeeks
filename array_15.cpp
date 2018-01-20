#include <iostream>
using namespace std;
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    int n;
    cin>>n;
    int c[10001]={0};
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      c[arr[i]]++;
    }
    // for(int i=0;i<n;i++)
    // {
    //   cout<<c[arr[i]]<<" ";
    // }
    // cout<<endl;
    int i=0;
    for(;i<n;i++)
    {
      if(c[arr[i]]>=2)
      {
        cout<<i+1<<endl;
        break;
      }
    }
    if(i==n)
    cout<<"-1"<<endl;
  }
}
