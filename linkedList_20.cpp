void deleteNode(Node *node)
{
   // Your code here
   if(node==NULL)
   return;
   Node* temp=node->next;
   node->data=temp->data;
   node->next=temp->next;
   delete temp;
}
