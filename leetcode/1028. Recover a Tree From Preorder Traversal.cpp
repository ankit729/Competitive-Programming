// We run a preorder depth-first search (DFS) on the root of a binary tree.

// At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

// If a node has only one child, that child is guaranteed to be the left child.

// Given the output S of this traversal, recover the tree and return its root.

 

// Example 1:


// Input: S = "1-2--3--4-5--6--7"
// Output: [1,2,5,3,4,6,7]
// Example 2:


// Input: S = "1-2--3---4-5--6---7"
// Output: [1,2,5,3,null,6,null,4,null,7]
// Example 3:


// Input: S = "1-401--349---90--88"
// Output: [1,401,null,349,88,90]
 

// Constraints:

// The number of nodes in the original tree is in the range [1, 1000].
// 1 <= Node.val <= 10^9

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
    TreeNode* recoverFromPreorder(string& s) {
        int i=0;
        stack<TreeNode*> st;
        while(s[i]){
            int depth=getDepth(s,i),val=getVal(s,i);
            TreeNode* node=new TreeNode(val);
            while(st.size()>depth)
                st.pop();
            if(!st.empty()){
                if(!st.top()->left)
                    st.top()->left=node;
                else
                    st.top()->right=node;
            }
            st.push(node);
        }
        while(st.size()>1)
            st.pop();
        return st.top();
    }
    int getVal(string& s, int& i) {
        int ans=0;
        while(s[i] && s[i]!='-')
            ans=ans*10+s[i++]-'0';
        return ans;
    }
    int getDepth(string& s, int& i) {
        int ans=0;
        while(s[i] && s[i]=='-')
            ans++,i++;
        return ans;
    }
};
