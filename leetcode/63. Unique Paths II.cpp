// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// Now consider if some obstacles are added to the grids. How many unique paths would there be?

// An obstacle and space is marked as 1 and 0 respectively in the grid.

 

// Example 1:


// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right
// Example 2:


// Input: obstacleGrid = [[0,1],[0,0]]
// Output: 1
 

// Constraints:

// m == obstacleGrid.length
// n == obstacleGrid[i].length
// 1 <= m, n <= 100
// obstacleGrid[i][j] is 0 or 1.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int R=grid.size(),C=grid[0].size();
        int dp[C];
        fill(dp,dp+C,0);
        dp[0]=1;
        for(int r=0;r<R;++r){
            if(grid[r][0])
                dp[0]=0;
            for(int c=1;c<C;++c){
                dp[c]=(grid[r][c])?0:dp[c-1]+dp[c];
            }
        }
        return dp[C-1];
    }
};
