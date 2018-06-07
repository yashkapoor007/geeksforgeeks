void deleteAlt(struct Node *head){
    // Code here
    Node* prev=head;
    Node* current=head->next;
    while(current&&current->next)
    {
        prev->next=current->next;
        delete current;
        prev=prev->next;
        current=prev->next;
    }
    prev->next=NULL;
}
