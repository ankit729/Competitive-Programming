// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

// Example 1:


// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: inorder = [-1], postorder = [-1]
// Output: [-1]
 

// Constraints:

// 1 <= inorder.length <= 3000
// postorder.length == inorder.length
// -3000 <= inorder[i], postorder[i] <= 3000
// inorder and postorder consist of unique values.
// Each value of postorder also appears in inorder.
// inorder is guaranteed to be the inorder traversal of the tree.
// postorder is guaranteed to be the postorder traversal of the tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        return helper(post,0,in,0,in.size());
    }
private:
    TreeNode* helper(vector<int>& post, int l1, vector<int>& in, int l2, int n) {
        if(n==0)
            return NULL;
        TreeNode* root=new TreeNode(post[l1+n-1]);
        int temp=find(in.begin()+l2,in.begin()+l2+n,post[l1+n-1])-in.begin();
        root->left=helper(post,l1,in,l2,temp-l2);
        root->right=helper(post,l1+temp-l2,in,temp+1,n-temp+l2-1);
        return root;
    }
};
