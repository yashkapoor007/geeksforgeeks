#include <iostream>
using namespace std;
int printmissing(int arr[],int start,int end)
{
    if(start>end)
    return end+1;
    if(start!=arr[start])
    return start;
    int mid=start+(end-start)/2;
    if(arr[mid]==mid)
    return printmissing(arr,mid+1,end);
    return printmissing(arr,start,mid);
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
    cout<<printmissing(arr,0,n-1);
    cout<<endl;
  }
}
