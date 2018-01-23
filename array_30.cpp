#include<bits/stdc++.h>
using namespace std;
struct pair1{
  int petrol;
  int distance;
};
int roundtrip(struct pair1 arr[],int n)
{
  int start=0;
  int end=1;
  int current_petrol=arr[start].petrol-arr[start].distance;
  while(start!=end || current_petrol<0)
  {
    while(current_petrol<0&&start!=end)
    {
      current_petrol-=arr[start].petrol-arr[start].distance;
      start=(start+1)%n;
      if(start==0)
      return -1;
    }
    current_petrol+=arr[end].petrol-arr[end].distance;
    end=(end+1)%n;
  }
  return start;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    struct pair1 arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i].petrol>>arr[i].distance;
    }
    if(roundtrip(arr,n)!=-1)
    cout<<roundtrip(arr,n)<<endl;
    else
    cout<<"-1"<<endl;
  }
}
