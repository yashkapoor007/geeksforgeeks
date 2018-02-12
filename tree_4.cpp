#include<iostream>
#include <queue>
#include "Tree.h"
using namespace std;
int findsum(Tree<int>* root,int sum)
{
  if(root==NULL)
  return sum==0;
  int ans=0;
  int subsum=sum-root->data;
  if(subsum==0&&root->children.size()==0)
  return 1;
  for(int i=0;i<root->children.size();i++)
  {
    ans=ans||findsum(root->children[i],subsum);
  }
  return ans;
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
  Tree<int>* root=takeInputLevelWise();
  int sum;
  cout<<"enter the sum to be found"<<endl;
  cin>>sum;
  int ans=findsum(root,sum);
  cout<<ans<<endl;
}
