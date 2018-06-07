#include<set>
Node *removeDuplicates(Node *root)
{
    unordered_set<int> s;
    Node* current=root;
    Node* prev=NULL;
    while(current)
    {
        if(s.find(current->data)!=s.end())
        {
            prev->next=current->next;
            delete current;
        }
        else
        {
            s.insert(current->data);
            prev=current;
        }
        current=current->next;
    }
    return root;
 // your code goes here
}
