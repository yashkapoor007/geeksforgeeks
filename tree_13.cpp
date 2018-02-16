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
int width(Btree<int>* root)
{
  queue<Btree<int>* > q;
  if(root==NULL)
  return 0;
  q.push(root);
  int result=0;
  while(!q.empty())
  {
    int count=q.size();
    result=max(count,result);
    while(count--)
    {
      Btree<int>* front=q.front();
      q.pop();
      if(front->left!=NULL)
      q.push(front->left);
      if(front->right!=NULL)
      q.push(front->right);
    }
  }
  return result;
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
  // vector<Btree<int>* > v;
  // printRootToLeaf(root,v);
  int maxwidth=width(root);
  cout<<"the maximum width is "<<maxwidth<<endl;
}
