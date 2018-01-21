#include <iostream>
#include <cmath>
using namespace std;
void printmissingrepeating(int arr[],int n)
{
  for(int i=0;i<n;i++)
  {
    if(arr[(int)abs(arr[i])-1]>0)
    arr[(int)abs(arr[i])-1]=-arr[(int)abs(arr[i])-1];
    else
    cout<<abs(arr[i])<<" ";
  }
  for(int i=0;i<n;i++)
  {
    if(arr[i]>0)
    cout<<i+1<<" ";
  }
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
  printmissingrepeating(arr,n);
    cout<<endl;
  }
}
