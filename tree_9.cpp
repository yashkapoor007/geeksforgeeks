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
int checkIdentical(Btree<int>* root1,Btree<int>* root2)
{
  int ans=1;
  if(root1==NULL&&root2==NULL)
  return 1;
  else if(root1==NULL&&root2!=NULL)
  return 0;
  else if(root1!=NULL&&root2==NULL)
  return 0;
  ans=ans&&checkIdentical(root1->left,root2->left);
  if(root1->data!=root2->data)
  {
    return 0;
  }
  ans=ans&&checkIdentical(root1->right,root2->right);
  return ans;
}

int main()
{
  cout<<"Input tree 1"<<endl;
  Btree<int> *root1=takeInputLevelWise();
  cout<<"Input tree 2"<<endl;
  Btree<int>* root2=takeInputLevelWise();
  cout<<checkIdentical(root1,root2);
  cout<<endl;
  //printInorderwithoutRecursionAndStack(root);
}
