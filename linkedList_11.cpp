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
int GetNth(Node* head, int index)
{
   // Code here
   if(index==1)
   return head->data;
   GetNth(head->next,index-1);
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
int search(Node* head,int &i,int x)
{
  if(head==NULL)
  {
    i=-1;
    return i;
  }
  if(head->data==x)
  return i;
  else
  {
    i++;
    search(head->next,i,x);
  }
}
Node* swap(Node* head,int x,int y)
{
  if(x==y)
  return head;
  Node *temp=head;
  Node* currX=head,*currY=head;
  Node* prevX=NULL,*prevY=NULL;
  while(currX&&currX->data!=x)
  {
    prevX=currX;
    currX=currX->next;
  }
  while(currY&&currY->data!=y)
  {
    prevY=currY;
    currY=currY->next;
  }
  if (currX == NULL || currY == NULL)
    return head;
  if(prevX!=NULL)
  {
    prevX->next=currY;
  }
  else
  {
    head=currY;
  }
  if(prevY!=NULL)
  {
    prevY->next=currX;
  }
  else
  {
    head=currX;
  }
  temp=currX->next;
  currX->next=currY->next;
  currY->next=temp;
  return head;
}
int main()
{
  Node* head=buildList();
  print(head);
  int k;
  cin>>k;
  cout<<GetNth(head,k)<<endl;
}
