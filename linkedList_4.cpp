#include<iostream>
#include "Node.cpp"
using namespace std;
Node* InsertAtBeginning(Node* head,int data)
{
      Node* newnode= new Node(data);
  if(head==NULL)
  {
    head=newnode;
  }
  else
  {
    newnode->next=head;
    head=newnode;
  }
  return head;
}
Node* InsertAtEnd(Node* head,int data)
{
  Node* newnode=new Node(data);
  if(head==NULL)
  {
    head=newnode;
  }
  else
  {
    Node* temp=head;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=newnode;
  }
  return head;
}
Node* buildList()
{
  Node* head=NULL;
  cout<<"enter data and action 0 - InsertAtBeginning 1 - InsertAtEnd"<<endl;
  int data=0,i;
  while(data!=-1)
  {
    cin>>data>>i;
    if(i==0&&data!=-1)
    head=InsertAtBeginning(head,data);
    else if(i==1&&data!=-1)
    head=InsertAtEnd(head,data);
  }
  return head;
}
void print(Node* head)
{
  Node* temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}
int main()
{
  Node* head=buildList();
  print(head);
}
