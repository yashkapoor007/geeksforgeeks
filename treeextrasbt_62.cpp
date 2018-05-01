#include<climits>
void findMaxHelper(struct node* root,int &max)
{
    if(root==NULL)
    return;
    if(root->left)
    findMaxHelper(root->left,max);
    if(max<root->data)
    max=root->data;
    if(root->right)
    findMaxHelper(root->right,max);
}
int findMax(struct node* root)
{
    int max=INT_MIN;
    findMaxHelper(root,max);
    return max;
// Your code goes here
}
void findMinHelper(struct node* root,int &min)
{
    if(root==NULL)
    return;
    if(root->left)
    findMinHelper(root->left,min);
    if(min>root->data)
    min=root->data;
    if(root->right)
    findMinHelper(root->right,min);
}
// Returns minimum value in a given Binary Tree
int findMin(struct node* root)
{
// Your code goes here
    int min=INT_MAX;
    findMinHelper(root,min);
    return min;
}
