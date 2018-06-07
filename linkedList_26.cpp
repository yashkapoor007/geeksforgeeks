void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
void pairWiseSwap(struct node *head)
{
   // The task is to complete this method
   if(!head||!head->next)
   return ;
   node* prev=head;
   node* current=head->next;
   swap(prev->data,current->data);
   pairWiseSwap(head->next->next);
}
