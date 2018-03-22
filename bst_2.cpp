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
BST<int>* successor(BST<int>* root)
{
  if(root==NULL)
  return root;
  while(root->left!=NULL)
  root=root->left;
  return root;
}
BST<int>* deleteNode(BST<int>* root,int key)
{
  if(root==NULL)
  return root;
  if(root->data<key)
  root->right=deleteNode(root->right,key);
  else if(root->data>key)
  root->left=deleteNode(root->left,key);
  else
  {
    if(root->left==NULL)
    {
      BST<int>* temp=root->right;
      delete root;
      return temp;
    }
    else if(root->right==NULL)
    {
      BST<int>* temp=root->left;
      delete root;
      return temp;
    }
    BST<int>* newNode=successor(root->right);

    root->data=newNode->data;
    root->right=deleteNode(root->right,newNode->data);
  }
  return root;
}
int main()
{
  BST<int>* root=buildTree();
  InOrder(root);
  cout<<endl;
  cout<<"enter the key to be deleted\n";
  int key;
  cin>>key;
  root=deleteNode(root,key);
  InOrder(root);
  cout<<endl;
  // cout<<"enter the value to be searched "<<endl;
  // int key;
  // cin>>key;
  // if(search(root,key))
  // cout<<"key found"<<endl;
  // else
  // cout<<"key not found"<<endl;
}
