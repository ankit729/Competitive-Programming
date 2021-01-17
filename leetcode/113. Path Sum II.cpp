// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

// Note: A leaf is a node with no children.

// Example:

// Given the below binary tree and sum = 22,

//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
// Return:

// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        vector<int> curr;
        helper(root,sum,curr,ans);
        return ans;
    }
private:
    void helper(TreeNode* root, int& sum, vector<int>& curr, vector<vector<int>>& ans) {
        curr.push_back(root->val);
        sum-=root->val;
        if(!root->left && !root->right){
            if(sum==0)
                ans.push_back(curr);
        }
        else{
            if(root->left)
                helper(root->left,sum,curr,ans);
            if(root->right)
                helper(root->right,sum,curr,ans);
        }
        sum+=root->val;
        curr.pop_back();
    }
};
