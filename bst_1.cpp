#include<iostream>
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
int search(BST<int>* root,int key)
{
  if(root==NULL)
  return 0;
  if(root->data==key)
  return 1;
  if(root->data<key)
  search(root->right,key);
  else if(root->data>key)
  search(root->left,key);
}
void InOrder(BST<int>* root)
{
  if(root==NULL)
  return;
  InOrder(root->left);
  cout<<root->data<<" ";
  InOrder(root->right);
}
int main()
{
  BST<int>* root=buildTree();
  InOrder(root);
  cout<<endl;
  cout<<"enter the value to be searched "<<endl;
  int key;
  cin>>key;
  if(search(root,key))
  cout<<"key found"<<endl;
  else
  cout<<"key not found"<<endl;
}
