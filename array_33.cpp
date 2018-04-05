#include<iostream>
#include<cstring>
using namespace std;
bool isSpecial(char c)
{
  if((c>=65&&c<=90)||(c>=97&&c<=122))
  return false;
  return true;
}
int main()
{
  string s;
  cin>>s;
  int l=s.length();
  int i=0,j=l-1;
  while(i<j)
  {
    if(isSpecial(s[i]))
    i++;
    else if(isSpecial(s[j]))
    j--;
    else
    {
      char c=s[i];
      s[i]=s[j];
      s[j]=c;
      i++;
      j--;
    }
  }
  cout<<s<<endl;
}
