#include<iostream>
#include<cstdlib>
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
void sortedInsert(Node** head, int data)
{
    // Code here
    if(*head==NULL)
    return;
    Node* temp=*head;
    Node* prev=NULL;
    while(temp&&temp->data<data)
    {
        prev=temp;
        temp=temp->next;
    }
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;
    if(temp==*head)
    {
        newnode->next=*head;
        *head=newnode;
    }
    else
    {
    prev->next=newnode;
    newnode->next=temp;
    }
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

int main()
{
  Node* head=buildList();
  print(head);
  int data;
  cin>>data;
  sortedInsert(&head,data);
  print(head);
}
