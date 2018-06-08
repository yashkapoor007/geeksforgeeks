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
Node*  addList(Node* first, Node* second){
  // Code here
  Node* result=NULL;
  Node* tail=NULL;
  int c=0;
  while(first&&second)
  {
      if(first->data+second->data+c>=10)
      {
          int data=(first->data+second->data+c)%10;
          c=1;
          Node* newnode=(Node*)malloc(sizeof(Node));
          newnode->next=NULL;
          newnode->data=data;
          if(result==NULL)
          {
              result=newnode;
              tail=result;
          }
          else
          {
              tail->next=newnode;
              tail=tail->next;
          }
      }
      else
      {
          int data=first->data+second->data+c;
          c=0;
          Node* newnode=(Node*)malloc(sizeof(Node));
          newnode->next=NULL;
          newnode->data=data;
          if(result==NULL)
          {
              result=newnode;
              tail=result;
          }
          else
          {
              tail->next=newnode;
              tail=tail->next;
          }
      }
      first=first->next;
      second=second->next;
  }
  while(first)
  {
      if(first->data+c>=10)
      {
          int data=(first->data+c)%10;
          c=1;
          Node* newnode=(Node*)malloc(sizeof(Node));
          newnode->next=NULL;
          newnode->data=data;
          if(result==NULL)
          {
              result=newnode;
              tail=result;
          }
          else
          {
              tail->next=newnode;
              tail=tail->next;
          }
      }
      else
      {
          int data=first->data+c;
          c=0;
          Node* newnode=(Node*)malloc(sizeof(Node));
          newnode->next=NULL;
          newnode->data=data;
          if(result==NULL)
          {
              result=newnode;
              tail=result;
          }
          else
          {
              tail->next=newnode;
              tail=tail->next;
          }
      }
      first=first->next;
  }
  while(second)
  {
      if(second->data+c>=10)
      {
          int data=(second->data+c)%10;
          c=1;
          Node* newnode=(Node*)malloc(sizeof(Node));
          newnode->next=NULL;
          newnode->data=data;
          if(result==NULL)
          {
              result=newnode;
              tail=result;
          }
          else
          {
              tail->next=newnode;
              tail=tail->next;
          }
      }
      else
      {
          int data=second->data+c;
          c=0;
          Node* newnode=(Node*)malloc(sizeof(Node));
          newnode->next=NULL;
          newnode->data=data;
          if(result==NULL)
          {
              result=newnode;
              tail=result;
          }
          else
          {
              tail->next=newnode;
              tail=tail->next;
          }
      }
      second=second->next;
  }
  if(c==1)
  {
      Node* newnode=(Node*)malloc(sizeof(Node));
          newnode->next=NULL;
          newnode->data=1;
          tail->next=newnode;
          tail=tail->next;
  }
  return result;
}
Node* reverse(Node* head,Node* prev=NULL)
{
    if(head==NULL)
    {
        head=prev;
        return head;
    }
    Node* next=head->next;
    head->next=prev;
    reverse(next,head);
}
int main()
 {
	//code
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        Node* head1=NULL,*head2=NULL;
        Node* tail1=NULL,*tail2=NULL;
        for(int i=0;i<n;i++)
        {
            int data;
            cin>>data;
            Node* newnode=new Node(data);
            tail1=insert(tail1,newnode);
            if(i==0)
            head1=tail1;
        }
        for(int i=0;i<m;i++)
        {
            int data;
            cin>>data;
            Node* newnode=new Node(data);
            tail2=insert(tail2,newnode);
            if(i==0)
            head2=tail2;
        }
        head1=reverse(head1);
        head2=reverse(head2);
        Node* result=addList(head1,head2);
        result=reverse(result);
        head1=reverse(head1);
        head2=reverse(head2);
        print(result);
        cout<<endl;
    }
	return 0;
}
