#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include "btree.h"
using namespace std;
int search(int arr[], int strt, int end, int value)
{
    for (int i = strt; i <= end; i++)
        if (arr[i] == value)
            return i;
    return -1;
}

// n is size of level[], m is size of in[] and m < n. This
// function extracts keys from level[] which are present in
// in[].  The order of extracted keys must be maintained
int *extractKeys(int in[], int level[], int m, int n)
{
    int *newlevel = new int[m], j = 0;
    for (int i = 0; i < n; i++)
        if (search(in, 0, m-1, level[i]) != -1)
            newlevel[j] = level[i], j++;
    return newlevel;
}
Btree<int>* buildTree(int* in,int* lev,int inS,int inE,int n)
{
  if(inS>inE)
  return NULL;
  Btree<int>* root=new Btree<int>(lev[0]);
  if(inS==inE)
  return root;
  int inIndex=search(in,inS,inE,root->data);
  int* llevel=extractKeys(in,lev,inIndex,n);
  int* rlevel=extractKeys(in+inIndex+1,lev,n-inIndex-1,n);
  root->left=buildTree(in,llevel,inS,inIndex-1,n);
  root->right=buildTree(in,rlevel,inIndex+1,inE,n);
  delete [] llevel;
delete [] rlevel;

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
//1 2 3 4 5 6 7 8 9 10 11 12 13 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
  int n;
  cout<<"Enter the number of elements in an array"<<endl;
  cin>>n;
  int in[n];
  int lev[n];
  for(int i=0;i<n;i++)
  cin>>in[i];
  for(int i=0;i<n;i++)
  cin>>lev[i];
  Btree<int>* newRoot=buildTree(in,lev,0,n-1,n);
  printInorder(newRoot);
  cout<<endl;
}
