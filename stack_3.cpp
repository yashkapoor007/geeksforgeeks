#include<stack>
void reverse(char *str, int len)
{
    stack<char> s;
// Your code goes here
    for(int i=0;i<len;i++)
    s.push(str[i]);
    int i=0;
    while(s.empty()!=1)
    {
        str[i]=s.top();
        s.pop();
        i++;
    }
}
