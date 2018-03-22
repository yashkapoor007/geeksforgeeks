#include <iostream>
#include <queue>
#include "btreevc.h"
using namespace std;
Btree<int>* takeInputLevelWise()
{
  cout<<"Enter the root data"<<endl;
  int rootdata;
  cin>>rootdata;
  if(rootdata==-1)
  return NULL;
  Btree<int>* root=new Btree<int>(rootdata);
  queue<Btree<int>* > q;
  q.push(root);
  while(q.size()>0)
  {
    Btree<int>* front=q.front();
    q.pop();
    cout<<"Enter the left child of "<<front->data<<endl;
    int lc;
    cin>>lc;
    if(lc!=-1)
    {
      front->left=new Btree<int>(lc);
      q.push(front->left);
    }
    cout<<"Enter the right child of "<<front->data<<endl;
    int rc;
    cin>>rc;
    if(rc!=-1)
    {
      front->right=new Btree<int>(rc);
      q.push(front->right);
    }
  }
  return root;
}

void printLevel(Btree<int>* root)
{
  if(root==NULL)
  {
    return;
  }
  queue<Btree<int>* > q;
  q.push(root);
  while(q.size()>0)
  {
    Btree<int>* front= q.front();
    q.pop();
    cout<<front->data<<" ";
    if(front->left)
    q.push(front->left);
    if(front->right)
    q.push(front->right);
  }
  cout<<endl;
}
Btree<int>* concat(Btree<int>* leftList,Btree<int>* rightList)
{
  if(leftList==NULL)
  return rightList;
  if(rightList==NULL)
  return leftList;

  Btree<int>* leftLast=leftList->left;
  Btree<int>* rightLast=rightList->left;

  leftLast->right=rightList;
  rightList->left=leftLast;

  leftList->left=rightLast;
  rightLast->right=leftList;

  return leftList;
}
Btree<int>* btreetoCDLL(Btree<int>* root)
{
  if(root==NULL)
  return NULL;
  Btree<int>* left=btreetoCDLL(root->left);
  Btree<int>* right=btreetoCDLL(root->right);

  root->left=root->right=root;

  return concat(concat(left,root),right);
}
void display(Btree<int>* head)
{
  Btree<int>* temp=head;
  while(temp->right!=head)
  {
    cout<<temp->data<<" ";
    temp=temp->right;
  }
  cout<<temp->data;
  cout<<endl;
}
int main()
{
  cout<<" Build the tree"<<endl;
  Btree<int> *root=takeInputLevelWise();
  // cout<<"size of minimum vector cover is: ";
  Btree<int>* head=btreetoCDLL(root);
  display(head);
  // cout<<"Level order print"<<endl;
  // printLevel(root);
}
