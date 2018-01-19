#include<iostream>
using namespace std;
int pivotedMin(int arr[],int low,int high)
{
  if(high<low)
  return arr[0];
  if(high==low)
  return arr[low];
  int mid=low+(high-low)/2;
  if(mid<high&&arr[mid+1]<arr[mid])
  return arr[mid+1];
  if(low<mid&&arr[mid]<arr[mid-1])
  return arr[mid];
  if(arr[high]>arr[mid])
  return pivotedMin(arr,low,mid-1);
  return pivotedMin(arr,mid+1,high);
}
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  int min=pivotedMin(arr,0,n-1);
  cout<<min<<endl;
}
