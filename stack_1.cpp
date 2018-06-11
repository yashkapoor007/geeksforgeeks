#include<iostream>
#include<stack>
using namespace std;
int prec(char p)
{
    switch(p)
    {
        case '^':
        return 3;
        case '*':
        case '/':
        return 2;
        case '+':
        case '-':
        return 1;
        case '(':
        return 0;
    }
}
int isChar(char c)
{
    if((c>=65&&c<=90)||(c>=97&&c<=122))
    return 1;
    return 0;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    stack<char>st;
	    int l=s.length();
	    for(int i=0;i<l;i++)
	    {
	        if(isChar(s[i]))
	        cout<<s[i];
	        else if(s[i]=='(')
	        st.push(s[i]);
	        else
	        {
	            if(s[i]==')')
	            {
	                while(st.empty()!=1&&st.top()!='(')
	                {
	                    cout<<st.top();
	                    st.pop();
	                }
	                if(!st.empty())
	                st.pop();
	            }
	            else
	            {
	                if(st.empty())
	                st.push(s[i]);
	                else
	                {
	                    while(st.empty()!=1&&st.top()!='('&&prec(st.top())>=prec(s[i]))
	                    {
	                        cout<<st.top();
	                        st.pop();
	                    }
	                    st.push(s[i]);
	                }
	            }
	        }
	    }
	    while(st.empty()!=1)
	    {
	        cout<<st.top();
	        st.pop();
	    }
	    cout<<endl;
	}
	return 0;
}
