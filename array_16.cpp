#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    int n;
    cin>>n;
    int arr[n+2];
    for(int i=0;i<n+2;i++)
    {
      cin>>arr[i];
    }
    for(int i=0;i<=n+1;i++)
    {
      if(arr[(int)abs(arr[i])]>0)
      arr[(int)abs(arr[i])]=-arr[(int)abs(arr[i])];
      else
      cout<<abs(arr[i])<<" ";
    }
    cout<<endl;
  }
}
