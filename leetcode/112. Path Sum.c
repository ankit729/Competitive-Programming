// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

// Note: A leaf is a node with no children.

// Example:

// Given the below binary tree and sum = 22,

//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \      \
// 7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool hasPathSum_Util(struct TreeNode* root,int sum){
    sum-=root->val;
    if(root->left==NULL && root->right==NULL && sum==0)
        return true;
    if(root->left!=NULL && hasPathSum_Util(root->left,sum))
        return true;
    if(root->right!=NULL && hasPathSum_Util(root->right,sum))
        return true;
    return false;
}
bool hasPathSum(struct TreeNode* root,int sum){
    if(root==NULL)
        return false;
    return hasPathSum_Util(root,sum);
}
