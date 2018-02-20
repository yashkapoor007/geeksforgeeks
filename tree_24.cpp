#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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
void bottomViewHelper(Btree<int>* root,map<int,pair<int,int> > &m,int hd,int level)
{
    if(root==NULL)
    return;
    if(m.find(hd)==m.end())
    {
        m[hd]=make_pair(root->data,level);
    }
    else
    {
        if(m[hd].second<=level)
        {
            m[hd].second=level;
            m[hd].first=root->data;
        }
    }
    bottomViewHelper(root->left,m,hd-1,level+1);
    bottomViewHelper(root->right,m,hd+1,level+1);
}
void bottomView(Btree<int> *root)
{
   // Your Code Here
   map<int,pair<int,int> >m;
   bottomViewHelper(root,m,0,0);
   map<int,pair<int,int> >::iterator it;
   for(it=m.begin();it!=m.end();it++)
   {
       cout<<it->second.first<<" ";
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
    cout<<"the left view of a tree is "<<endl;
    bottomView(root);
}
