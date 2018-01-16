#include<iostream>
using namespace std;
void rotate(char **arr,int n,int m)
{
  for(int j=0;j<=m-1;j++)
  {
    for(int i=n-1;i>=0;i--)
    cout<<arr[i][j];
    cout<<endl;
  }
}
int main()
{
  int n,m;
  cout<<"input the dimensions"<<endl;
  cin>>n>>m;
  char **arr=new char*[n];
  for(int i=0;i<=n-1;i++)
  arr[i]=new char[m];
  for(int i=0;i<=n-1;i++)
  {for(int j=0;j<=m-1;j++)
  {cin>>arr[i][j];}}
  rotate(arr,n,m);

}
