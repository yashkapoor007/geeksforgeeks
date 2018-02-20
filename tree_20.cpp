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
bool printAncestorsHelper(Btree<int>* root,int target,vector<int> v)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->data==target)
    {
        for(int i=v.size()-1;i>=0;i--)
        cout<<v[i]<<" ";
        cout<<endl;
        return 1;
    }
    v.push_back(root->data);
    int ans1=printAncestorsHelper(root->left,target,v);
    int ans2=printAncestorsHelper(root->right,target,v);
    return ans1||ans2;
}
bool printAncestors(Btree<int> *root, int target)
{
    vector<int> v;
     return printAncestorsHelper(root,target,v);
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
  int target;
  cout<<"enter the target key"<<endl;
  cin>>target;
  printAncestors(root,target);
  //printInorder(newRoot);
}
