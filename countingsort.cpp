#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
void countingsort(int arr[],int n)
{
  int c[10]={0};
  for(int i=0;i<n;i++)
  {
    c[arr[i]]++;
  }
  for(int i=1;i<10;i++)
  c[i]+=c[i-1];
  int newarr[n];
  for(int i=0;i<n;i++)
  {
    if(c[arr[i]]-1>=0)
    {
      newarr[c[arr[i]]-1]=arr[i];
      c[arr[i]]--;
    }
  }
  for(int i=0;i<n;i++)
  arr[i]=newarr[i];
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    int n=s.length();
    int arr[n];
    for(int i=0;i<n;i++)
    arr[i]=int(s[i]-'0');
    int mine=12;
    int mini=-1;
    for(int i=0;i<n;i++)
    {
      if(arr[i]%2==0&&arr[i]<mine)
      {
        mine=arr[i];
        mini=i;
      }
    }
    if(mini!=-1)
    {
      int t=arr[0];
      arr[0]=mine;
      arr[mini]=t;
      countingsort(arr+1,n-1);
    }
    else
    countingsort(arr,n);
    for(int i=n-1;i>=0;i--)
    cout<<arr[i];
    cout<<endl;
  }
}
