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
void printInorderwithoutRecursion(Btree<int>* root)
{
  stack<Btree<int>* >s;
  if(root==NULL)
  return;
  Btree<int>* top=root;
  int done=0;
  while(!done)
  {

    if(top!=NULL)
    {
      s.push(top);
      top=top->left;
    }
    else
    {
      if(s.size()!=0)
      {
        top=s.top();
        cout<<top->data<<" ";
        s.pop();
        top=top->right;
      }
      else
      done=1;
    }
  }
}
void pre(Btree<int>* root,int x,int &f,int& val)
{
  if(root==NULL)
  return;
  pre(root->left,x,f,val);
  if(root->data==x)
  {
    f=1;
    return;
  }
  if(f==0)
  {
    val=root->data;
  }
  pre(root->right,x,f,val);
}
int main()
{
  Btree<int> *root=takeInputLevelWise();
  printInorder(root);
  cout<<endl;
  int val=0;
  int x=5;
  int f=0;
  pre(root,x,f,val);
  cout<<val<<endl;
}
