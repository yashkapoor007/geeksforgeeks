#include <iostream>
#include <queue>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  cin>>arr[i];
  priority_queue<int> p;
  cout<<"enter k"<<endl;
  int k;
  cin>>k;
  for(int i=0;i<k;i++)
  p.push(arr[i]);
  for(int i=k;i<n;i++)
  {
    if(p.top()>arr[i])
    {
      p.pop();
      p.push(arr[i]);
    }
  }
  for(int i=0;i<k;i++)
  {
    cout<<p.top()<<" ";
    p.pop();
  }
  cout<<endl;
}
