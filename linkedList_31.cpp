node* newnode(int data)
{
    node* n=(node*)malloc(sizeof(node));
    n->next=NULL;
    n->data=data;
    return n;
}
void alternatingSplitList(struct node* headRef, struct node** aRef, struct node** bRef)
{
    // Code here
    if(headRef==NULL)
    return;
    int i=1;
    node* atail,*btail;
    while(headRef)
    {
        if(i%2==1)
        {
            if(*aRef==NULL)
            {
                *aRef=newnode(headRef->data);
                atail=*aRef;
            }
            else
            {
                atail->next=newnode(headRef->data);
                atail=atail->next;
            }
        }
        else
        {
            if(*bRef==NULL)
            {
                *bRef=newnode(headRef->data);
                btail=*bRef;
            }
            else
            {
                btail->next=newnode(headRef->data);
                btail=btail->next;
            }
        }
        i++;
        headRef=headRef->next;
    }
}
