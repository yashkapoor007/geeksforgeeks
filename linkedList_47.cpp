#include<vector>
#include<algorithm>
Node *flatten(Node *root)
{
   // Your code here
   vector<int> v;
   Node* n=root;
   while(n)
   {
       Node* b=n;
   while(b)
   {
       v.push_back(b->data);
       b=b->bottom;
   }
   n=n->next;
   }
   sort(v.begin(),v.end());
//   cout<<v.size()<<endl;
   Node* newroot=NULL;
   Node* tail=NULL;
   for(int i=0;i<v.size();i++)
   {
       Node* newnode=(Node*)malloc(sizeof(Node));
       newnode->next=NULL;
       newnode->bottom=NULL;
       newnode->data=v[i];
    //   cout<<v[i]<<" ";
       if(newroot==NULL)
       {
           newroot=newnode;
           tail=newroot;
       }
       else
       {
           tail->bottom=newnode;
           tail=tail->bottom;
       }
   }

   return newroot;
}
