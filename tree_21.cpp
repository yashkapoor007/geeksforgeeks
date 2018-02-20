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
Btree<int>* LCA(Btree<int>* root,int target1,int target2)
{
  if(root==NULL)
  return NULL;
  if(root->data==target1||root->data==target2)
  return root;
  Btree<int>* t1=LCA(root->left,target1,target2);
  Btree<int>* t2=LCA(root->right,target1,target2);
  if(t1!=NULL&&t2!=NULL)
  return root;
  else
  return t1!=NULL?t1:t2;
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
  int target1,target2;
  cout<<"enter the target keys"<<endl;
  cin>>target1>>target2;
  Btree<int>* node=LCA(root,target1,target2);
  cout<<"the least common ancestor is "<<node->data<<endl;
  }
