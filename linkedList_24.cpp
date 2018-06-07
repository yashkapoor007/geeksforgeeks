Node *removeDuplicates(Node *root)
{
 // your code goes here
 Node* current=root;
 while(current->next!=NULL)
 {
     Node* next=current->next;
     while(next&&current->data==next->data)
     {
         next=next->next;
     }
     if(next!=current->next)
     current->next=next;
     else
     current=next;
 }
 return root;
}
