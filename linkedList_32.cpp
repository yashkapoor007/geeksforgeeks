bool areIdentical(struct Node *head1, struct Node *head2)
{
    // Code here
    if(head1==NULL&&head2!=NULL)
    return false;
    if(head1!=NULL&&head2==NULL)
    return false;
    if(head1==NULL&&head2==NULL)
    return true;
    if(head1->data==head2->data)
    return areIdentical(head1->next,head2->next);
    else
    return false;
}
