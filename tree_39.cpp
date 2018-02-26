#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<climits>
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
int maxsumhelper(Btree<int>* root,int &res)
{
  if(root==NULL)
  return INT_MIN;
  if(root->left==NULL&&root->right==NULL)
  return root->data;
  int ls=maxsumhelper(root->left,res);
  int rs=maxsumhelper(root->right,res);
  if(root->left!=NULL&&root->right!=NULL)
  {
    res=max(res,ls+rs+root->data);
    return max(ls,rs)+root->data;
  }
  return (!root->left)?rs+root->data:ls+root->data;
}
int maxsum(Btree<int>* root)
{
  int res=INT_MIN;
  maxsumhelper(root,res);
  return res;
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
    int maxleaftoleafsum=maxsum(root);
    cout<<maxleaftoleafsum;
    cout<<endl;
}
