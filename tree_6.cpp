#include<iostream>
#include <queue>
#include <vector>
#include "Tree.h"
using namespace std;
void printKdistance(Tree<int>* root,int k)
{
  if(root==NULL)
  return;
  if(k==0)
  {
    cout<<root->data<<" ";
    return;
  }
  for(int i=0;i<root->children.size();i++)
  printKdistance(root->children[i],k-1);
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
//1 3 2 3 4 3 5 6 7 0 0 0 0 0
int main()
{
  vector<int> v;
  Tree<int>* root=takeInputLevelWise();
  int k;
  cout<<"enter the distance"<<endl;
  cin>>k;
  printKdistance(root,k);

}
