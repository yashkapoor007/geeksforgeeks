struct node* findIntersection(struct node* head1, struct node* head2)
{
    int *arr1=new int[1001];
    int *arr2=new int[1001];
    for(int i=0;i<1001;i++)
    {
        arr1[i]=0;
        arr2[i]=0;
    }
    node* result=NULL;
    node* tail=NULL;
    node* temp1=head1;
    node* temp2=head2;
    while(temp1)
    {
        arr1[temp1->data]++;
        temp1=temp1->next;
    }
    while(temp2)
    {
        arr2[temp2->data]++;
        temp2=temp2->next;
    }
    for(int i=0;i<1001;i++)
    {
        int min=arr1[i]>arr2[i]?arr2[i]:arr1[i];
        while(min)
        {
            node* newnode=(node*)malloc(sizeof(node));
            newnode->next=NULL;
            newnode->data=i;
            if(result==NULL)
            {
                result=newnode;
                tail=newnode;
            }
            else
            {
                tail->next=newnode;
                tail=tail->next;
            }
            min--;
        }
    }
    delete []arr1;
    return result;
}
