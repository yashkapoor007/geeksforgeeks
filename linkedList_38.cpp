int detectloop(struct node *list){
// your code goes here
    struct node* slow=list;
    struct node* fast=list->next;
    while(fast&&fast->next)
    {
        if(slow==fast)
        return 1;
        slow=slow->next;
        fast=fast->next->next;
    }
    return 0;
}
