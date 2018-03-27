#include<iostream>
#include<climits>
#include "bst.h"
using namespace std;
BST<int>* insert(BST<int>* root,BST<int>* node)
{
  if(root==NULL)
  return node;
  if(root->data<node->data)
  {
    root->right=insert(root->right,node);
  }
  else if(root->data>node->data)
  {
    root->left=insert(root->left,node);
  }
  return root;
}
BST<int>* buildTree()
{
  int rootData;
  cout<<"enter the root "<<endl;
  cin>>rootData;
  if(rootData==-1)
  return NULL;
  BST<int>* root=new BST<int>(rootData);
  while(1)
  {
    int data;
    cout<<"enter the value to be inserted\n";
    cin>>data;
    if(data==-1)
    break;
    BST<int>* node=new BST<int>(data);
    insert(root,node);
  }
  return root;
}
void InOrder(BST<int>* root)
{
  if(root==NULL)
  return;
  InOrder(root->left);
  cout<<root->data<<" ";
  InOrder(root->right);
}
BST<int>* minValue(BST<int>* root)
{
  if(root->left==NULL)
  return root;
  minValue(root->left);
}
BST<int>* inordersuccessor(BST<int>* root,BST<int>* x)
{
  if(x->right)
  return minValue(root->right);
  BST<int>* succ=NULL;
  while(root!=NULL)
  {
    if(root->data>x->data)
    {
      succ=root;
      root=root->left;
    }
    else
    root=root->right;
  }
  return succ;
}
int main()
{
  BST<int>* root=buildTree();
  InOrder(root);
  cout<<endl;
  int data;
  cout<<"enter the value whole successor has to be found"<<endl;
  cin>>data;
  BST<int>* x=new BST<int>(data);
  BST<int>* inordersucc=inordersuccessor(root,x);
  if(inordersucc==NULL)
  cout<<"-1"<<endl;
  else
  cout<<inordersucc->data<<endl;
}
