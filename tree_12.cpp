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
int TreeHeight(Btree<int>* root)
{
  int ans=0;
  if(root==NULL)
  return 0;
  int height=TreeHeight(root->left);
  if(ans<height)
  ans=height;
  height=TreeHeight(root->right);
  if(ans<height)
  ans=height;
  return ans+1;
}
int diameter(Btree<int>* root)
{
  if(root==NULL)
  return 0;
  return max(max(diameter(root->left),diameter(root->right)),TreeHeight(root->left)+TreeHeight(root->right)+1);

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
  int dia=diameter(root);
  cout<<dia<<endl;
}
