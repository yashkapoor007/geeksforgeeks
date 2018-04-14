#include <iostream>
using namespace std;
int pivotize(int arr[],int s,int e)
{
  int pivot=arr[e];
  int count=s-1;
  for(int j=s;j<e;j++)
  {
    if(arr[j]<=pivot)
    {
      count++;
      int t=arr[j];
      arr[j]=arr[count];
      arr[count]=arr[j];
    }
  }
  count++;
  int t=arr[count];
  arr[count]=arr[e];
  arr[e]=t;
  return count;
}
void quickselect(int arr[],int s,int e,int &k)
{
  if(s>e)
  return;
  int pivot=pivotize(arr,s,e);
  // cout<<pivot<<endl;
  if(k-1==pivot-s)
  {
    cout<<arr[pivot]<<endl;
    return;
  }
  quickselect(arr,s,pivot-1,k);
  quickselect(arr,pivot+1,e,k);
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    int k;
	    cin>>k;
	    quickselect(arr,0,n-1,k);
	}
	return 0;
}
