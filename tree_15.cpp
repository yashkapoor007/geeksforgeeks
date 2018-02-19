#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
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
int height(Btree<int>* root)
{
  if(root==NULL)
  return 0;
  return 1+max(height(root->left),height(root->right));
}
int heightbalanced(Btree<int>* root)
{
  if(root==NULL)
  return 1;
  return (abs(height(root->left)-height(root->right))<2)&&heightbalanced(root->left)&&heightbalanced(root->right);
}
void printInorder(Btree<int>* root)
{
  if(root==NULL)
  return;
  printInorder(root->left);
  cout<<root->data<<" ";
  printInorder(root->right);
}
//1 2 3 4 5 6 7 8 9 10 11 12 13 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
  Btree<int> *root=takeInputLevelWise();
  // vector<Btree<int>* > v;
  // printRootToLeaf(root,v);
  cout<<heightbalanced(root)<<endl;

}
