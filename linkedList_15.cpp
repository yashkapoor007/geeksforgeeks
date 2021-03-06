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
int count(Node* head, int search_for)
{
//add your code here
    if(head==NULL)
    return 0;
    if(search_for==head->data)
    return 1 + count(head->next,search_for);
    else
    count(head->next,search_for);
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
int length(Node* head)
{
  if(head==NULL)
  return 0;
  return 1+length(head->next);
}
Node* deleteAlinkedList(Node* head)
{
  Node* temp=head;
  while(temp)
  {
    Node* temp1=temp;
    temp=temp->next;
    delete temp1;
  }
  return NULL;
}
int main()
{
  Node* head=buildList();
  print(head);
  int x;
  cin>>x;
  cout<<count(head,x)<<endl;
}
