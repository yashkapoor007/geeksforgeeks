#include <iostream>
#include <queue>
#include "btreevc.h"
using namespace std;
Btree<int>* takeInputLevelWise()
{
  cout<<"Enter the root data"<<endl;
  int rootdata;
  cin>>rootdata;
  if(rootdata==-1)
  return NULL;
  Btree<int>* root=new Btree<int>(rootdata);
  queue<Btree<int>* > q;
  q.push(root);
  while(q.size()>0)
  {
    Btree<int>* front=q.front();
    q.pop();
    cout<<"Enter the left child of "<<front->data<<endl;
    int lc;
    cin>>lc;
    if(lc!=-1)
    {
      front->left=new Btree<int>(lc);
      q.push(front->left);
    }
    cout<<"Enter the right child of "<<front->data<<endl;
    int rc;
    cin>>rc;
    if(rc!=-1)
    {
      front->right=new Btree<int>(rc);
      q.push(front->right);
    }
  }
  return root;
}

void printLevel(Btree<int>* root)
{
  if(root==NULL)
  {
    return;
  }
  queue<Btree<int>* > q;
  q.push(root);
  while(q.size()>0)
  {
    Btree<int>* front= q.front();
    q.pop();
    cout<<front->data<<" ";
    if(front->left)
    q.push(front->left);
    if(front->right)
    q.push(front->right);
  }
  cout<<endl;
}
int vectorcover(Btree<int>* root)
{
  if(root==NULL)
  return 0;
  if(root->left==NULL&&root->right==NULL)
  return 0;
  if(root->vc!=0)
  return root->vc;
  int inc=1+vectorcover(root->left)+vectorcover(root->right);
  int exc=0;
  if(root->left)
  exc+=1+vectorcover(root->left->left)+vectorcover(root->left->right);
  if(root->right)
  exc+=1+vectorcover(root->right->left)+vectorcover(root->right->right);
  root->vc= min(inc,exc);
  return root->vc;
}
int main()
{
  cout<<" Build the tree"<<endl;
  Btree<int> *root=takeInputLevelWise();
  cout<<"size of minimum vector cover is: ";
  cout<<vectorcover(root)<<endl;
  // cout<<"Level order print"<<endl;
  // printLevel(root);
}
