#include <iostream>
#include<cstring>
using namespace std;
void rev(char ch[],int l)
{
  string s1="";
  for(int i=l-1;i>=0;i--)
  s1+=ch[i];
  cout<<s1<<endl;
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
    char ch[l+1];
    strcpy(ch,s.c_str());
    rev(ch,l);
  }
	return 0;
}
