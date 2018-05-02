void helper(Node* root,int &odd,int &even,int k)
{
    if(root==NULL)
    return;
    if(root->left)
    helper(root->left,odd,even,k+1);
    if(k%2==0)
    even+=root->data;
    else
    odd+=root->data;
    if(root->right)
    helper(root->right,odd,even,k+1);
}
int getLevelDiff(Node *root)
{
   //Your code here
   int odd=0;
   int even=0;
   helper(root,odd,even,1);
   return odd-even;
}
