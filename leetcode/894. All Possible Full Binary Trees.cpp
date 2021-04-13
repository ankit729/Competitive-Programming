// Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

// Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

// A full binary tree is a binary tree where each node has exactly 0 or 2 children.

 

// Example 1:


// Input: n = 7
// Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
// Example 2:

// Input: n = 3
// Output: [[0,0,0]]
 

// Constraints:

// 1 <= n <= 20

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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(!(n&1))
            return {};
        n>>=1;
        vector<TreeNode*> a[n+1];
        a[0].push_back(new TreeNode(0));
        for(int i=1;i<=n;++i)
            for(int l=0,r=i-1;l<i;++l,--r)
                for(auto& left:a[l])
                    for(auto& right:a[r])
                        a[i].push_back(new TreeNode(0,left,right));
        return a[n];
    }
};
