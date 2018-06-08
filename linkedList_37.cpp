#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        next=NULL;
        this->data=data;
    }
};
Node* insert(Node* tail,Node* node)
{
    if(tail==NULL)
    {
        tail=node;
    }
    else
    {
        tail->next=node;
        tail=tail->next;
    }
    return tail;
}
void print(Node* head)
{
    if(head==NULL)
    {
        return;
    }
    cout<<head->data<<" ";
    print(head->next);
}
Node* evenodd(Node* head,Node* tail)
{
    Node* curr=head;
    Node* prev=NULL;
    Node* tailtemp=tail;
    while(curr!=tailtemp)
    {
        if(curr->data%2!=0)
        {
            if(head==curr)
            {
                head=curr->next;
                tail->next=curr;
                tail=tail->next;
                curr->next=NULL;
                curr=head;
            }
            else
            {
            prev->next=curr->next;
            tail->next=curr;
            tail=tail->next;
            curr->next=NULL;
            curr=prev->next;
            }
        }
        else
        {
            prev=curr;
            curr=curr->next;
        }
    }if(tail!=tailtemp&&curr->data%2!=0)
    {
        if(curr==head)
        {
                head=curr->next;
                tail->next=curr;
                tail=tail->next;
                curr->next=NULL;
                curr=head;
        }
        else
        {
            prev->next = curr->next;
            tail->next = curr;
            tail=tail->next;
            tail->next = NULL;
        }
    }
    return head;
}
int main()
 {
	//code
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Node* head=NULL;
        Node* tail=NULL;
        for(int i=0;i<n;i++)
        {
            int data;
            cin>>data;
            Node* newnode=new Node(data);
            tail=insert(tail,newnode);
            if(i==0)
            head=tail;
        }
        // cout<<tail->data;
        head=evenodd(head,tail);
        print(head);
        cout<<endl;
    }
	return 0;
}
