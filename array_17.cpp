#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
void printduplicates(int arr[],int n)
{
  int f=0;
  for(int i=0;i<n;++i)
{
    int newIndex=arr[i];

    /* if this position is >=n, it means it has already been referred to multiple times */
    if(newIndex>=n)
        newIndex-=n;
    /* if this position is <0 , it means we have referred to this element exactly once */
    else if(newIndex < 0)
        newIndex+=n;

    /* if element is occuring for the second time  */
    if(arr[newIndex]<0)
         {
            cout<<newIndex<<" ";
            arr[newIndex]+=2*n;
            f=1;
         }
    /*if the element newIndex refers to is occuring for the first time */
    else if(arr[newIndex]<n)
        {
            arr[newIndex]-=n;
        }

}
if(f==0)
cout<<"-1";
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
    printduplicates(arr,n);
    cout<<endl;
  }
}
