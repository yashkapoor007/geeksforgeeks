void helper(Node* root,int &sum)
{
    if(root==NULL)
    return ;
    if(root->left)
    helper(root->left,sum);
    if(root->left&&root->left->left==NULL&&root->left->right==NULL)
    sum+=root->left->data;
    if(root->right)
    helper(root->right,sum);
}
int leftLeafSum(Node* root)
{
    // Code here
    int sum=0;
    helper(root,sum);
    return sum;
}
