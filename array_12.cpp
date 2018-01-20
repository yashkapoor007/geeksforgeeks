#include <iostream>
using namespace std;
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    int n;
    cin>>n;
    int sum=n*(n+1)/2;
    int newsum=0;
    for(int i=0;i<n-1;i++)
    {
      int a;
      cin>>a;
      newsum+=a;
    }
    cout<<sum-newsum<<endl;
  }
}
