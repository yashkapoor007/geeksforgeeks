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
Node* merge(Node* head1,Node* head2)
{
  if(head1==NULL)
  return head2;
  if(head2==NULL)
  return head1;
  Node* result=NULL;
  if(head1->data<head2->data)
  {
    result=head1;
    result->next=merge(head1->next,head2);
  }
  else
  {
    result=head2;
    result->next=merge(head1,head2->next);
  }
  return result;
}
int main()
{
  Node* head1=buildList();

  Node* head2=buildList();

  print(head1);
  print(head2);
  Node* head3=merge( head1,head2);
  print(head3);
}
