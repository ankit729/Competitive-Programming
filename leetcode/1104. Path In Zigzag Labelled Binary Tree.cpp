// In an infinite binary tree where every node has two children, the nodes are labelled in row order.

// In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.



// Given the label of a node in this tree, return the labels in the path from the root of the tree to the node with that label.

 

// Example 1:

// Input: label = 14
// Output: [1,3,4,14]
// Example 2:

// Input: label = 26
// Output: [1,2,6,10,26]
 

// Constraints:

// 1 <= label <= 10^6

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int next=nextP2(label);
        while(label){
            ans.push_back(label);
            label>>=1;
            next>>=1;
            label=next-label+(next>>1)-1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
private:
    int nextP2(int x) {
        x|=x>>1;
        x|=x>>2;
        x|=x>>4;
        x|=x>>8;
        x|=x>>16;
        return x+1;
    }
};
