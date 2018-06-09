void sortedInsert(Node** head, int x)
{
   //Your code here
   Node* newnode=(Node*)malloc(sizeof(Node));
   newnode->next=newnode;
   newnode->data=x;
   Node* curr=*head;
   if(curr==NULL)
   {
       *head=newnode;
       newnode->next=newnode;
   }
   else if(curr->data>=newnode->data)
   {
       Node* temp=curr;
       while(temp->next!=*head)
       {
           temp=temp->next;
       }
       temp->next=newnode;
       newnode->next=*head;
       *head=newnode;
   }
   else
   {
       curr=*head;
       while(curr->next!=*head&&curr->next->data<x)
       curr=curr->next;
       newnode->next=curr->next;
       curr->next=newnode;
   }
}
