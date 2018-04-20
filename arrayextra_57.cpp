#include <iostream>
#include <cstdlib>
using namespace std;
int pivotize(int arr[],int s,int e)
{
  int piv=arr[e];
  int i=s;
  for(int j=s;j<e;j++)
  {
    if(arr[j]<=piv)
    {
      int t=arr[j];
      arr[j]=arr[i];
      arr[i]=t;
      i++;
    }
  }
  int t=arr[e];
  arr[e]=arr[i];
  arr[i]=t;
  return i;
}
int pivotize_r(int arr[],int s,int e)
{
  srand(time(NULL));
  int rp=s+rand()%(e-s);
  int t=arr[rp];
  arr[rp]=arr[e];
  arr[e]=t;
  return pivotize(arr,s,e);
}
void randomQuick(int arr[],int s,int e)
{
  if(s>=e)
  return;
  int p=pivotize_r(arr,s,e);
  randomQuick(arr,s,p-1);
  randomQuick(arr,p+1,e);
}
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
    randomQuick(arr,0,n-1);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
  }
}
