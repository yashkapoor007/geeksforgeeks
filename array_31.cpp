#include<bits/stdc++.h>
using namespace std;
bool compare(string X,string Y)
{
  string XY=X.append(Y);
  string YX=Y.append(X);
  return(XY.compare(YX))>0?1:0;
}
void largestnumber(string arr[],int n)
{
    sort(arr,arr+n,compare);
    for(int i=0;i<n;i++)
    cout<<arr[i];
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    largestnumber(arr,n);
    cout<<endl;
  }
}
