Node *compute(Node *head)
{
// your code goes here
    if(head==NULL||head->next==NULL)
    return head;
    Node* curr=head;
    Node* prev=NULL;
    while(curr->next)
    {
        int flag=0;
        Node* next=curr->next;
        while(next)
        {
            if(curr->data<next->data)
            {
                flag=1;
                break;
            }
            next=next->next;
        }
        if(flag==1)
        {
            if(curr==head)
            {
                head=curr->next;
                delete curr;
                curr=head;
            }
            else
            {prev->next=curr->next;
            delete curr;
            curr=prev->next;
            }
        }
        else
        {
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}
