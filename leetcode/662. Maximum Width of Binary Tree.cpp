// Given a binary tree, write a function to get the maximum width of the given tree. The maximum width of a tree is the maximum width among all levels.

// The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

// It is guaranteed that the answer will in the range of 32-bit signed integer.

// Example 1:

// Input: 

//            1
//          /   \
//         3     2
//        / \     \  
//       5   3     9 

// Output: 4
// Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
// Example 2:

// Input: 

//           1
//          /  
//         3    
//        / \       
//       5   3     

// Output: 2
// Explanation: The maximum width existing in the third level with the length 2 (5,3).
// Example 3:

// Input: 

//           1
//          / \
//         3   2 
//        /        
//       5      

// Output: 2
// Explanation: The maximum width existing in the second level with the length 2 (3,2).
// Example 4:

// Input: 

//           1
//          / \
//         3   2
//        /     \  
//       5       9 
//      /         \
//     6           7
// Output: 8
// Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).
 

// Constraints:

// The given binary tree will have between 1 and 3000 nodes.

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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        if(!root)
            return 0;
        queue<pair<TreeNode*,unsigned int>> q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            pair<TreeNode*,unsigned int> curr;
            unsigned int left=q.front().second;
            while(n--){
                curr=q.front();
                q.pop();
                if(curr.first->left)
                    q.push({curr.first->left,curr.second<<1});
                if(curr.first->right)
                    q.push({curr.first->right,(curr.second<<1)|1});
            }
            ans=max(ans,static_cast<int> (curr.second-left+1));
        }
        return ans;
    }
};
