#include <iostream>
#include <cmath>
using namespace std;
void printoddoccuring(int arr[],int n)
{
  int xor2=0,x=0,y=0;
  for(int i=0;i<n;i++)
  {
    xor2^=arr[i];
  }
  int setbit=xor2&~(xor2-1);
  for(int i=0;i<n;i++)
  {
    if(arr[i]&setbit)
    x^=arr[i];
    else
    y^=arr[i];
  }
  if(x>y)
  cout<<x<<" "<<y;
  else
  cout<<y<<" "<<x;
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
  printoddoccuring(arr,n);
    cout<<endl;
  }
}
