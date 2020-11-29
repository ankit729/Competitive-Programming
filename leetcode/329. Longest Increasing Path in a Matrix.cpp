// Given an integer matrix, find the length of the longest increasing path.

// From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

// Example 1:

// Input: nums = 
// [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ] 
// Output: 4 
// Explanation: The longest increasing path is [1, 2, 6, 9].
// Example 2:

// Input: nums = 
// [
//   [3,4,5],
//   [3,2,6],
//   [2,2,1]
// ] 
// Output: 4 
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int R=matrix.size(),C=(R?matrix[0].size():0);
        int ans=0;
        vector<vector<int>> dp(R,vector<int>(C,0));
        for(int i=0;i<R;++i)
            for(int j=0;j<C;++j)
                ans=max(ans,solve(matrix,R,C,i,j,dp));
        return ans;
    }
private:
    int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    int solve(vector<vector<int>>& matrix, int& R, int& C, int r, int c, vector<vector<int>>& dp) {
        if(dp[r][c])
            return dp[r][c];
        int ans=0;
        for(int i=0;i<4;++i){
            int nr=r+dir[i][0],nc=c+dir[i][1];
            if(nr>=0 && nr<R && nc>=0 && nc<C && matrix[nr][nc]>matrix[r][c])
                ans=max(ans,solve(matrix,R,C,nr,nc,dp));
        }
        return dp[r][c]=1+ans;
    }
};
