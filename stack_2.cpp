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
	    stack<int> st;
	    int l=s.length();
	    for(int i=0;i<l;i++)
	    {
	        if(s[i]=='*')
	        {
	            int a=st.top();
	            st.pop();
	            int b=st.top();
	            st.pop();
	            int ans=a*b;
	            st.push(ans);
	        }
	        else if(s[i]=='/')
	        {
	            int a=st.top();
	            st.pop();
	            int b=st.top();
	            st.pop();
	            int ans=b/a;
	            st.push(ans);
	        }
	        else if(s[i]=='+')
	        {
	            int a=st.top();
	            st.pop();
	            int b=st.top();
	            st.pop();
	            int ans=a+b;
	            st.push(ans);
	        }
	        else if(s[i]=='-')
	        {
	            int a=st.top();
	            st.pop();
	            int b=st.top();
	            st.pop();
	            int ans=b-a;
	            st.push(ans);
	        }
	        else
	        {
	            st.push(int(s[i]-'0'));
	        }
	    }
	    cout<<st.top()<<endl;
	    st.pop();
	}
	return 0;
}
