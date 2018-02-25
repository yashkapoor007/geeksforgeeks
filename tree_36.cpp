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
void printSpiral(Btree<int> *node)
{
     //Your code here
     if(node==NULL)
     return;
     stack<Btree<int>* > s1;
     stack<Btree<int>* > s2;
     s1.push(node);
     while(s1.size()>0||s2.size()>0)
     {
         while(s1.size()>0)
         {
             Btree<int>* top=s1.top();
             s1.pop();
             cout<<top->data<<" ";
             if(top->right)
             s2.push(top->right);
             if(top->left)
             s2.push(top->left);
         }
         while(s2.size()>0)
         {
             Btree<int>* top=s2.top();
             s2.pop();
             cout<<top->data<<" ";
             if(top->left)
             s1.push(top->left);
             if(top->right)
             s1.push(top->right);
         }
     }
             return;
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
  cout<<"Input tree"<<endl;
    Btree<int> *root=takeInputLevelWise();
    printSpiral(root);
    cout<<endl;
}
