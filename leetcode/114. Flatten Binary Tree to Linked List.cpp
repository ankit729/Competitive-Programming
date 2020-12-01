// Given a binary tree, flatten it to a linked list in-place.

// For example, given the following tree:

//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// The flattened tree should look like:

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6

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
    void flatten(TreeNode* root) {
        dfs(root);
    }
private:
    TreeNode* dfs(TreeNode* root) {
        if(!root)
            return NULL;
        if(root->left){
            TreeNode* right=root->right;
            root->right=root->left;
            root->left=NULL;
            TreeNode* tail=dfs(root->right);
            tail->right=right;
            return (right)?dfs(right):tail;
        }
        return root->right?dfs(root->right):root;
    }
};
auto fastIO=[](){std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
