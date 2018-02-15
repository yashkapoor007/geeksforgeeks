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
void printInorder(Btree<int>* root)
{
  if(root==NULL)
  return;
  printInorder(root->left);
  cout<<root->data<<" ";
  printInorder(root->right);
}
void printInorderwithoutRecursionAndStack(Btree<int>* root)
{
  if(root==NULL)
  return;
  Btree<int>* current=root,*pre;
  while(current!=NULL)
  {
    if(current->left==NULL)
    {
      cout<<current->data<<" ";
      current=current->right;
    }
    else
    {
    pre=current->left;
    while(pre->right!=NULL&&pre->right!=current)
    pre=pre->right;
    if(pre->right==NULL)
    {
      pre->right=current;
      current=current->left;
    }
    else
    {
      pre->right=NULL;
      cout<<current->data<<" ";
      current=current->right;
    }
  }
  }
}
int main()
{
  Btree<int> *root=takeInputLevelWise();
  printInorder(root);
  cout<<endl;
  printInorderwithoutRecursionAndStack(root);
  cout<<endl;
}
