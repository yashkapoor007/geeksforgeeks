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
void printVerticalHelper(Btree<int>* root,int hd,map<int, vector<int> > &m)
{
  if(root==NULL)
  return;
  m[hd].push_back(root->data);
  printVerticalHelper(root->left,hd-1,m);
  printVerticalHelper(root->right,hd+1,m);
}
void printVertical(Btree<int>* root)
{
  map<int,vector<int> > m;
  printVerticalHelper(root,0,m);
  map<int,vector<int> > ::iterator it;
  for(it=m.begin();it!=m.end();it++)
  {
    vector<int> v=it->second;
    for(int i=0;i<v.size();i++)
    {
      cout<<v[i]<<" ";
    }
    cout<<"$";
  }
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
    printVertical(root);
    cout<<endl;// cout<<endl;
}
