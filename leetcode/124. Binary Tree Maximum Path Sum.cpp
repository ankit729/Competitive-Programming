// Given a non-empty binary tree, find the maximum path sum.

// For this problem, a path is defined as any node sequence from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

 

// Example 1:


// Input: root = [1,2,3]
// Output: 6
// Example 2:


// Input: root = [-10,9,20,null,null,15,7]
// Output: 42
 

// Constraints:

// The number of nodes in the tree is in the range [0, 3 * 104].
// -1000 <= Node.val <= 1000

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
    int ans=INT_MIN;
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
private:
    int solve(TreeNode* root) {
        if(!root)
            return 0;
        int left_max=solve(root->left);
        int right_max=solve(root->right);
        ans=max(ans,left_max+root->val+right_max);
        return max(max(max(left_max,right_max)+root->val,root->val),0);
    }
};
