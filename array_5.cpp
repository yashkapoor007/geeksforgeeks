#include<iostream>
#include<climits>
using namespace std;
class minmax{
public:
  int max;
  int min;
  minmax()
  {
    max=INT_MIN;
    min=INT_MAX;
  }
};
minmax minmaxfind(int arr[],int n)
{
  minmax m;
  int i;
  if(n%2==0)
  {
    if(arr[0]>arr[1])
    {
      m.max=arr[0];
      m.min=arr[1];
    }
    else
    {
      m.min=arr[0];
      m.max=arr[1];
    }
    i=2;
  }
  else
  {
    m.max=arr[0];
    m.min=arr[0];
    i=1;
  }
  while(i<n-1)
  {
    if(arr[i]>arr[i+1])
    {
      if(arr[i]>m.max)
      m.max=arr[i];
      if(arr[i+1]<m.min)
      m.min=arr[i+1];
    }
    else
    {
      if(arr[i]<m.min)
      m.min=arr[i];
      if(arr[i+1]>m.max)
      m.max=arr[i+1];
    }
    i+=2;
  }
  return m;                                                                                                              
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
    cin>>arr[i];
    minmax temp= (minmax)minmaxfind(arr,n);
    cout<<temp.max<<" "<<temp.min<<endl;
  }
}
