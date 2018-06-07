
#include<set>
Node *removeDuplicates(Node *root)
{
   unordered_set<int> s;
   Node* current=root;
   Node* prev=NULL;
   while(current)
   {
       if(s.find(current->val)!=s.end())
       {
           prev->next=current->next;
           delete current;
       }
       else
       {
           s.insert(current->val);
           prev=current;
       }
       current=current->next;
   }
   return root;
// your code goes here
}
void intersection(Node **head1, Node **head2,Node **head3)
{
   if(*head1==NULL||*head2==NULL)
   {
       *head3=NULL;
       return;
   }
   *head1=removeDuplicates(*head1);
   *head2=removeDuplicates(*head2);
   unordered_set<int> s;
   while((*head1))
   {
       s.insert((*head1)->val);
       (*head1)=(*head1)->next;
   }
   Node* tail;
   while((*head2))
   {
       if(s.find((*head2)->val)!=s.end())
       {
           if(*head3==NULL)
           {
               Node* newnode=(Node*)malloc(sizeof(Node));
               newnode->val=(*head2)->val;
               newnode->next=NULL;
               *head3=newnode;
               tail=newnode;
           }
           else
           {
               Node* temp=*head3;
               Node* newnode=(Node*)malloc(sizeof(Node));
               newnode->val=(*head2)->val;
               newnode->next=NULL;
               tail->next=newnode;
               tail=tail->next;
           }
       }
       (*head2)=(*head2)->next;
   }
   // Your Code Here
}
