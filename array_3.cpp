#include <iostream>
#include<cstring>
using namespace std;
void swap(char &s1,char &s2)
{
  char temp=s1;
  s1=s2;
  s2=temp;
}
void rev(string &s,int l,int h)
{
  if(l>=h)
  return;
  swap(s[l],s[h]);
  rev(s,l+1,h-1);
}
int main() {
	//code
  int T;
  cin>>T;
  while(T--)
  {
    string s;
    cin>>s;
    int l=s.length();
    rev(s,0,l-1);
    cout<<s<<endl;
  }
	return 0;
}
