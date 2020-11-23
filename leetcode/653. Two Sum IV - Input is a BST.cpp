// Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

 

// Example 1:


// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true
// Example 2:


// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false
// Example 3:

// Input: root = [2,1,3], k = 4
// Output: true
// Example 4:

// Input: root = [2,1,3], k = 1
// Output: false
// Example 5:

// Input: root = [2,1,3], k = 3
// Output: true
 

// Constraints:

// The number of nodes in the tree is in the range [1, 10^4].
// -10^4 <= Node.val <= 10^4
// root is guaranteed to be a valid binary search tree.
// -10^5 <= k <= 10^5

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
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        finTargetInOrder(root,nums);
        int l=0,r=nums.size()-1;
        while(l<r){
            int sum=nums[l]+nums[r];
            if(sum==k)
                return true;
            if(sum<k)
                l++;
            else
                r--;
        }
        return false;
    }
private:
    void finTargetInOrder(TreeNode* root, vector<int>& nums) {
        if(!root)
            return;
        finTargetInOrder(root->left,nums);
        nums.push_back(root->val);
        finTargetInOrder(root->right,nums);
    }
};
