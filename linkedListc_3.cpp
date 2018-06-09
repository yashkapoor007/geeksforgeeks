void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    if(head==NULL)
    return;
    if(head->next==NULL)
    {*head1_ref=head;return;}
    *head1_ref=head;
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=head&&fast->next!=head)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    *head2_ref=slow->next;
    slow->next=head;
    slow=*head2_ref;
    while(slow->next!=head)
    {
        slow=slow->next;
    }
    slow->next=*head2_ref;
}
