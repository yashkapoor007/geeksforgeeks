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
Btree<int>* currentTree(int* in,int* pre,int inS,int inE)
{
  static int preIndex=0;
  if(inS>inE)
  return NULL;
  int rootData=pre[preIndex++];
  Btree<int>* root=new Btree<int>(rootData);
  if(inS==inE)
  return root;

  int rootIndex=-1;
  for(int i=inS;i<=inE;i++)
  {
    if(in[i]==rootData)
    {rootIndex=i;break;}
  }

  // cout<<rootData<<endl;
  root->left=currentTree(in,pre,inS,rootIndex-1);
  root->right=currentTree(in,pre,rootIndex+1,inE);
  return root;
}
void printInorder(Btree<int>* root)
{
  if(root==NULL)
  return;
  printInorder(root->left);
  cout<<root->data<<" ";
  printInorder(root->right);
}
void printPostOrder(Btree<int>* root)
{
  if(root==NULL)
  return;
  printPostOrder(root->left);
  printPostOrder(root->right);
  cout<<root->data<<" ";
}
//1 2 3 4 5 6 7 8 9 10 11 12 13 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
  //Btree<int> *root=takeInputLevelWise();
  // vector<Btree<int>* > v;
  // printRootToLeaf(root,v);
  int n;
  cout<<"Enter the number of elements in an array"<<endl;
  cin>>n;
  int in[n];
  int pre[n];
  for(int i=0;i<n;i++)
  cin>>in[i];
  for(int i=0;i<n;i++)
  cin>>pre[i];
  Btree<int>* newRoot=currentTree(in,pre,0,n-1);
  printPostOrder(newRoot);
  cout<<endl;
}
