#include<iostream>
#include<climits>
using namespace std;
struct min_2min
{
  int first;
  int second;
};
struct min_2min min(int arr[],int n)
{
  int l1=arr[0],l2=INT_MAX;
  struct min_2min t;
  for(int i=1;i<n;i++)
  {
    if(l1>arr[i])
    {
      l2=l1;
      l1=arr[i];
    }
    else if(arr[i]>l1 && arr[i]<l2)
    l2=arr[i];
  }
  t.first=l1;
  if(n>1)
  t.second=l2;
  else
  t.second=t.first;
  return t;
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
    min_2min ans=min(arr,n);
    if(ans.first!=ans.second&&ans.second!=INT_MAX)
    cout<<ans.first<<" "<<ans.second<<endl;
    else
    cout<<"-1"<<endl;
  }
}
