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
bool isBSTHelper(BST<int>* root,int min,int max)
{
  if(root==NULL)
  return 1;
  if(root->data<min||root->data>max)
  return 0;
  return isBSTHelper(root->left,min,root->data-1)&&isBSTHelper(root->right,root->data+1,max);
}
bool isBST(BST<int>* root)
{
  return isBSTHelper(root,INT_MIN,INT_MAX);
}
int main()
{
  BST<int>* root=buildTree();
  InOrder(root);
  cout<<endl;
  int isbst=isBST(root);
  if(isbst)
  cout<<"it is a bst"<<endl;
  else
  cout<<"it is not a bst"<<endl;
}
