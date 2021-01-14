// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;bool flag=true;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> temp(n);
            for(int i=0;i<n;++i){
                root=q.front();
                q.pop();
                temp[flag?i:n-1-i]=root->val;
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            ans.push_back(move(temp));
            flag=!flag;
        }
        return ans;
    }
};
