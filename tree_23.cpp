#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include "btree.h"
using namespace std;
Btree<int>* takeInputLevelWise()
{
  int rootdata;
  cout<<"enter root data"<<endl;
  cin>>rootdata;
  if(rootdata==-1)
  return NULL;
  Btree<int>* root=new Btree<int>(rootdata);
  queue<Btree<int>* > pendingnodes;
  pendingnodes.push(root);
  // int i=0;
  while(pendingnodes.size()>0)
  {
    Btree<int>* front=pendingnodes.front();
    pendingnodes.pop();
    int lc;
    int rc;
    cout<<"enter the left child of "<<front->data<<endl;
    cin>>lc;
    if(lc!=-1)
    {
      Btree<int>* leftchild=new Btree<int>(lc);
      front->left=leftchild;
      pendingnodes.push(leftchild);
    }
    cout<<"enter the right child of "<<front->data<<endl;
    cin>>rc;
    if(rc!=-1)
    {
      Btree<int>* rightchild=new Btree<int>(rc);
      front->right=rightchild;
      pendingnodes.push(rightchild);
    }
    // i++;
    // cout<<i<<endl;
  }
  return root;
}
void printLeftView(Btree<int>* root)
{
  queue<Btree<int>* > q;
  if(root==NULL)
  return;
  q.push(root);
  while(q.size()>0)
  {
      Btree<int>* front;
    int count=q.size();
    int flag=0;
    while(count)
    {
      front= q.front();
      q.pop();
      if(flag==0)
      {
        cout<<front->data<<" ";
        flag=1;
      }
      if(front->left)
      q.push(front->left);
      if(front->right)
      q.push(front->right);
      count--;
    }
    // cout<<q.size();
  }
  cout<<endl;
}
void printInorder(Btree<int>* root)
{
  if(root==NULL)
  return;
  printInorder(root->left);
  cout<<root->data<<" ";
  printInorder(root->right);
}

int main()
{
    Btree<int> *root=takeInputLevelWise();
    cout<<"the left view of a tree is "<<endl;
    printLeftView(root);
}
