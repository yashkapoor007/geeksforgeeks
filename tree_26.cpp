#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
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
void leftboundaryView(Btree<int>* root,vector<int> &v)
{
      if(root==NULL)
  return;
  if(root->left==NULL&& root->right==NULL)
  return ;
      if(root->left)
      {
          v.push_back(root->data);
          leftboundaryView(root->left,v);
      }
      else if(root->right)
      {
          v.push_back(root->data);
          leftboundaryView(root->right,v);
      }
  return;
}
void leafs(Btree<int>* root,vector<int> &v)
{
      if(root==NULL)
  return;
   leafs(root->left,v);
  if(root->left==NULL&&root->right==NULL)
  {
    v.push_back(root->data);
    return;
  }
  leafs(root->right,v);
  return;
}
void rightboundaryview(Btree<int>* root,vector<int> &v)
{
      if(root==NULL)
  return;
  if(root->left==NULL&&root->right==NULL)
  {
    return;
  }
  if(root->right)
  {rightboundaryview(root->right,v);
  {if(find(v.begin(),v.end(),root->data)==v.end())
  v.push_back(root->data);}}
  else if(root->left)
  {
  rightboundaryview(root->left,v);
  {if(find(v.begin(),v.end(),root->data)==v.end())
  v.push_back(root->data);}}
  return;
}
void printBoundary(Btree<int> *root)
{
     //Your code here
    vector<int> v;
    if(root)
    v.push_back(root->data);
    leftboundaryView(root->left,v);
    leafs(root->left,v);
    leafs(root->right,v);
    rightboundaryview(root->right,v);
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
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
    cout<<"the boundaryView of a tree is "<<endl;
    printBoundary(root);
    // cout<<endl;
}
