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
    int uniq=0;
    for(int i=0;i<n;i++)
    {
      int a;
      cin>>a;
      uniq^=a;
    }
    cout<<uniq<<endl;
  }
}
