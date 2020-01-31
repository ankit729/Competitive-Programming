// Given a binary tree, return the sum of values of its deepest leaves.
 

// Example 1:



// Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
// Output: 15
 

// Constraints:

// The number of nodes in the tree is between 1 and 10^4.
// The value of nodes is between 1 and 100.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}
int findmaxdepth(struct TreeNode* root,int depth){
    int a=depth,b=depth;
    if(root->left!=NULL)
        a=findmaxdepth(root->left,depth+1);
    if(root->right!=NULL)
        b=findmaxdepth(root->right,depth+1);
    return max(a,b);
}
int findsum(struct TreeNode* root,int maxdepth,int depth,int sum){
    if(root==NULL)
        return 0;
    if(depth==maxdepth)
        return root->val;
    return findsum(root->left,maxdepth,depth+1,sum)+findsum(root->right,maxdepth,depth+1,sum);
}
int deepestLeavesSum(struct TreeNode* root){
    return findsum(root,findmaxdepth(root,0),0,0);
}
