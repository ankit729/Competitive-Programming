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

int min(int a,int b){
    return (a<b)?a:b;
}
int minPathSum(int** grid, int r, int* c){
    if(r==0 || c[0]==0)
        return 0;
    int dp[c[0]];
    dp[0]=grid[0][0];
    for(int i=1;i<c[0];i++)
        dp[i]=grid[0][i]+dp[i-1];
    for(int i=1;i<r;i++){
        dp[0]+=grid[i][0];
        for(int j=1;j<c[i];j++)
            dp[j]=grid[i][j]+min(dp[j],dp[j-1]);
    }
    return dp[c[0]-1];
}
