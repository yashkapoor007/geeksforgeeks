#include<map>
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    map<Node*,int> m;
    Node* temp1=head1;
    while(temp1)
    {
        m.insert(make_pair(temp1,temp1->data));
        temp1=temp1->next;
    }
    Node* temp2=head2;
    while(temp2)
    {
        if(m.find(temp2)!=m.end())
        return temp2->data;
        temp2=temp2->next;
    }
    return -1;
}
