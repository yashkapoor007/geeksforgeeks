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
void storeinorder(Btree<int>* root,vector<int> &vin)
{
  if(root==NULL)
  return;
  storeinorder(root->left,vin);
  vin.push_back(root->data);
  storeinorder(root->right,vin);
}
void storepreorder(Btree<int>* root,vector<int> &vpre)
{
  if(root==NULL)
  return;
  vpre.push_back(root->data);
  storepreorder(root->left,vpre);
  storepreorder(root->right,vpre);
}
bool checksubtreehelper(vector<int> v1,vector<int> v2)
{
  for(int i=0;i<v1.size();i++)
  {
    int j;
    for(j=0;j<v2.size();j++)
    {
      if(v1[i+j]!=v2[j])
      break;
    }
    if(j==v2.size())
    return true;
  }
  return false;
}
bool checksubtree(Btree<int> *root1,Btree<int> *root2)
{
  vector<int> vin1;
  vector<int> vin2;
  vector<int> vpre1;
  vector<int> vpre2;
  storeinorder(root1,vin1);
  storeinorder(root2,vin2);
  storepreorder(root1,vpre1);
  storepreorder(root2,vpre2);
  bool flag1=checksubtreehelper(vin1,vin2);
  bool flag2=checksubtreehelper(vpre1,vpre2);
  return flag1&&flag2;
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
  cout<<"Input tree 1"<<endl;
    Btree<int> *root1=takeInputLevelWise();
    cout<<"Input tree 2"<<endl;
    Btree<int> *root2=takeInputLevelWise();
    if(checksubtree(root1,root2))
    cout<<"It is a subtree"<<endl;
    else
    cout<<"It is not a subtree"<<endl;
}
