#include<iostream>
#include <queue>
#include <vector>
#include "Tree.h"
using namespace std;
void printrootleaf(Tree<int>* root,vector<int> v)
{
  if(root==NULL)
  return;
  v.push_back(root->data);
  if(root->children.size()==0)
  {
    for(int i=0;i<v.size();i++)
    {
      cout<<v[i]<<" ";
    }
    cout<<endl;
    return;
  }
  for(int i=0;i<root->children.size();i++)
  printrootleaf(root->children[i],v);
  return;
}
Tree<int>* takeInputLevelWise()
{
  cout<<"enter the root data "<<endl;
  int rootdata;
  cin>>rootdata;
  Tree<int>* root=new Tree<int>(rootdata);
  queue<Tree<int>*> pendingnodes;
  pendingnodes.push(root);
  while(pendingnodes.size()>0)
  {
    Tree<int>* front=pendingnodes.front();
    pendingnodes.pop();
    cout<<"enter the number of children of "<<front->data<<endl;
    int numchild;
    cin>>numchild;
    for(int i=0;i<numchild;i++)
    {
      cout<<"Enter the "<<i+1<<" child of "<<front->data<<endl;
      int childdata;
      cin>>childdata;
      Tree<int>* child=new Tree<int>(childdata);
      front->children.push_back(child);
      pendingnodes.push(child);
    }
  }
  return root;
}
//1 2 2 3 2 4 5 0 0 0
int main()
{
  vector<int> v;
  Tree<int>* root=takeInputLevelWise();
  printrootleaf(root,v);

}
