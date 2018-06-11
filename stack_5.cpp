#include<iostream>
#include<stack>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    stack<char> st;
	    int l=s.length();
	    int f=0;
	    for(int i=0;i<l;i++)
	    {
	        if(s[i]=='('||s[i]=='{'||s[i]=='[')
	        st.push(s[i]);
	        else
	        {
	            if(st.empty())
	            {
	                f=1;
	                break;
	            }
	            if((st.top()=='('&&s[i]==')')||(st.top()=='{'&&s[i]=='}')||(st.top()=='['&&s[i]==']'))
	            st.pop();
	            else
	            {f=1;break;}
	        }
	    }
	if(f==1||!st.empty())
	cout<<"not balanced";
	else
	cout<<"balanced";
	cout<<endl;
	}
	return 0;
}
