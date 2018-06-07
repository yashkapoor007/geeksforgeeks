#include<iostream>
#include "Node.cpp"
using namespace std;
Node* buildList()
{
  Node* head=NULL;
  Node* tail=NULL;
  int data=0;
  while(data!=-1)
  {
    cin>>data;
    if(data!=-1)
    {
      Node* newnode=new Node(data);
      if(head==NULL)
      {head=newnode;
        tail=newnode;
      }
      else if(head!=NULL)
      {
          tail->next=newnode;
          tail=tail->next;
      }
    }

  }
  return head;
}

Node* deleteANode(Node* head,int x)
{
  Node* temp=head;
    if(x==1)
    {
        temp=head;
        head=head->next;
        delete temp;
    }
    else
    {
      for(int i=1;i<x-1;i++)
      {
        temp=temp->next;
      }
      Node* temp1=temp->next;
      temp->next=temp1->next;
      delete temp1;
    }
    return head;
}
Node* reverseAlinkedList(Node* head,Node* prev=NULL)
{
  if(head==NULL)
  {
    head=prev;
    return prev;
  }
  Node* next=head->next;
  head->next=prev;
  reverseAlinkedList(next,head);
}
void print(Node* head)
{
  if(head==NULL)
  cout<<"empty"<<endl;
  Node* temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}
Node* ltf(Node* head)
{
  if(head==NULL||head->next==NULL)
  return head;
  Node *prev=head;
  Node* current=head->next;
  while(current->next)
  {
    prev=current;
    current=current->next;
  }
  current->next=head;
  prev->next=NULL;
  head=current;
  return head;
}
void printreverse(Node* head)
{
  if(head==NULL)
  {
    return;
  }
  printreverse(head->next);
  cout<<head->data<<" ";
}
int main()
{
  Node* head=buildList();
  print(head);
  head=ltf(head);
  print(head);
}
