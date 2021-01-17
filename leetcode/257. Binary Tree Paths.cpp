// Given a binary tree, return all root-to-leaf paths.

// Note: A leaf is a node with no children.

// Example:

// Input:

//    1
//  /   \
// 2     3
//  \
//   5

// Output: ["1->2->5", "1->3"]

// Explanation: All root-to-leaf paths are: 1->2->5, 1->3

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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return {};
        vector<string> ans;
        string s;
        helper(root,s,ans);
        return ans;
    }
private:
    void helper(TreeNode* root, string& s, vector<string>& ans) {
        if(!root->left && !root->right){
            ans.push_back(s);
            ans.back()+=to_string(root->val);
            return;
        }
        s+=to_string(root->val)+"->";
        if(root->left)
            helper(root->left,s,ans);
        if(root->right)
            helper(root->right,s,ans);
        do{
            s.pop_back();
        }while(!s.empty() && s.back()!='>');
    }
};
