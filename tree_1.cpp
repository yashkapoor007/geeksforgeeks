#include<iostream>
#include <queue>
#include "Tree.h"
using namespace std;
int TreeHeight(Tree<int>* root)
{
  int ans=0;
  for(int i=0;i<root->children.size();i++)
  {
    int height=TreeHeight(root->children[i]);
    if(ans<height)
    ans=height;
  }
  return ans+1;
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
int main()
{
  Tree<int>* root=takeInputLevelWise();
  int height=TreeHeight(root);
  cout<<"the height of the tree is "<<height<<endl;
}
