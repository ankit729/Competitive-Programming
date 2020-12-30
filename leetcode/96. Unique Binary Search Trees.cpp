// Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

// Example:

// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
 

// Constraints:

// 1 <= n <= 19

class Solution {
public:
    int numTrees(int n) {
        int f[n+1];
        f[0]=1;
        for(int i=1;i<=n;++i){
            f[i]=0;
            for(int j=0;j<i;++j)
                f[i]+=f[j]*f[i-1-j];
        }
        return f[n];
    }
};
