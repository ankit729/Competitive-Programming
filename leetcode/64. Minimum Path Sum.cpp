// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

// Example:

// Input:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// Output: 7
// Explanation: Because the path 1→3→1→1→1 minimizes the sum.

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int R=grid.size(),C=(R?grid[0].size():0);
        vector<int> dp(C,INT_MAX);
        dp[0]=0;
        for(int i=0;i<R;++i){
            dp[0]+=grid[i][0];
            for(int j=1;j<C;++j)
                dp[j]=grid[i][j]+min(dp[j-1],dp[j]);
        }
        return dp[C-1];
    }
};
