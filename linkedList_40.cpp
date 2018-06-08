#include<vector>
Node *addOne(Node *head)
{
   // Your Code here
   Node* head2=head;
   vector<int> v;
   while(head2)
   {
       v.push_back(head2->data);
       head2=head2->next;
   }
   int c=0;
   for(int i=v.size()-1;i>=0;i--)
   {
       if(i==v.size()-1)
       {
          if(v[i]+1>=10)
          {
              v[i]=(v[i]+1)%10;
              c=1;
          }
        else
          {
                v[i]=v[i]+1;
                c=0;
          }
       }
       else
       {
           if(v[i]+c>=10)
          {
              v[i]=(v[i]+c)%10;
              c=1;
          }
        else
          {
                v[i]=v[i]+c;
                c=0;
          }
       }
   }
   for(int i=0;i<v.size();i++)
   {
       cout<<v[i];
   }
   return NULL;
}
