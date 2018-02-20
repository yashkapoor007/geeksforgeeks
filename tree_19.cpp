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
void serialize(Btree<int>* root,vector<int> &v)
{
  if(root==NULL)
  {
    v.push_back(-1);
    return;
  }
  v.push_back(root->data);
  serialize(root->left,v);
  serialize(root->right,v);
}
Btree<int>* deserializeHelper(vector<int> &v,int &index)
{
  if(v[index]==-1)
  {
    index++;
    return NULL;
  }
  Btree<int>* root=new Btree<int>(v[index++]);
  root->left=deserializeHelper(v,index);
  root->right=deserializeHelper(v,index);
  return root;
}
Btree<int>* deserialize(vector<int> &v)
{
  int index=0;
  return deserializeHelper(v,index);
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
  vector<int> v;
  serialize(root,v);
  Btree<int>* newRoot= deserialize(v);
  printInorder(newRoot);
  cout<<endl;
}
