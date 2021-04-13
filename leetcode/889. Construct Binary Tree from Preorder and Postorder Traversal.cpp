// Return any binary tree that matches the given preorder and postorder traversals.

// Values in the traversals pre and post are distinct positive integers.

 

// Example 1:

// Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
// Output: [1,2,3,4,5,6,7]
 

// Note:

// 1 <= pre.length == post.length <= 30
// pre[] and post[] are both permutations of 1, 2, ..., pre.length.
// It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.

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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n=pre.size();
        TreeNode dummy(0);
        TreeNode* curr=&dummy;
        stack<TreeNode*> st;
        st.push(curr);
        for(int i=0,j=0;i<n;++i){
            if(!curr->left){
                curr->left=new TreeNode(pre[i]);
                curr=curr->left;
            }
            else{
                curr->right=new TreeNode(pre[i]);
                curr=curr->right;
            }
            st.push(curr);
            while(j<n && (st.top()->val==post[j] || st.top()->right))
                st.pop(),j++;
            curr=st.top();
        }
        return dummy.left;
    }
};
