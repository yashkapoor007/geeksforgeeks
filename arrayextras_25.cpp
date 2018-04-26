#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
{
  int t=a;
  a=b;
  b=t;
}
void shuffle(int arr[],int n)
{
  for(int i=0;i<n;i++)
  {
    int j=rand()%n;
    swap(arr[i],arr[j]);
  }
}
int main()
{
  int t;
  cin>>t;
  srand(time(NULL));
  while(t--)
  {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
  shuffle(arr,n);
  for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
  cout<<endl;
  }
}
