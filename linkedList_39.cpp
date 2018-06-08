Node* detectloop(Node* node)
{
    Node* curr=node;
    Node* fast=node;
    int ans=0;
    while(curr&&fast&&fast->next)
    {
        curr=curr->next;
        fast=fast->next->next;
        if(curr==fast)
        {
            ans=1;
            break;
        }
    }
    if(ans==1)
    {
        curr=node;
        while(curr!=fast)
        {
            curr=curr->next;
            fast=fast->next;
        }
        while(curr!=fast->next)
        {
            fast=fast->next;
        }
        return fast;
    }
    return NULL;
}
void removeTheLoop(Node *node)
{
     //Your code here
     node=detectloop(node);
     if(node)
     node->next=NULL;
     return;
}
