void sortList(Node *head)
{
   //Add code here
   Node* curr=head;
   int arr[3]={0};
   while(curr)
   {
       arr[curr->data]++;
       curr=curr->next;
   }
   curr=head;
   for(int i=0;i<3;i++)
   {
       int min=arr[i];
       while(min)
       {
           curr->data=i;
           curr=curr->next;
           min--;
       }
   }
}
