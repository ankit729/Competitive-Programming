// In a N x N grid representing a field of cherries, each cell is one of three possible integers.

 

// 0 means the cell is empty, so you can pass through;
// 1 means the cell contains a cherry, that you can pick up and pass through;
// -1 means the cell contains a thorn that blocks your way.
 

// Your task is to collect maximum number of cherries possible by following the rules below:

 

// Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or down through valid path cells (cells with value 0 or 1);
// After reaching (N-1, N-1), returning to (0, 0) by moving left or up through valid path cells;
// When passing through a path cell containing a cherry, you pick it up and the cell becomes an empty cell (0);
// If there is no valid path between (0, 0) and (N-1, N-1), then no cherries can be collected.
 

 

// Example 1:

// Input: grid =
// [[0, 1, -1],
//  [1, 0, -1],
//  [1, 1,  1]]
// Output: 5
// Explanation: 
// The player started at (0, 0) and went down, down, right right to reach (2, 2).
// 4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
// Then, the player went left, up, up, left to return home, picking up one more cherry.
// The total number of cherries picked up is 5, and this is the maximum possible.
 

// Note:

// grid is an N by N 2D array, with 1 <= N <= 50.
// Each grid[i][j] is an integer in the set {-1, 0, 1}.
// It is guaranteed that grid[0][0] and grid[N-1][N-1] are not -1.

int max(int a,int b){
    return (a>b)?a:b;
}
int cherryPickup_dp(int r,int** grid,int dp[r][r][r],int r1,int c1,int c2){
    int r2=r1+c1-c2;
    if(r1==r || c1==r || r2==r || c2==r || grid[r1][c1]==-1 || grid[r2][c2]==-1)
        return INT_MIN+1;
    if(r1==r-1 && c1==r-1)
        return grid[r-1][r-1];
    if(dp[r1][c1][c2]!=INT_MIN)
        return dp[r1][c1][c2];
    int a=grid[r1][c1]+((r1!=r2)?grid[r2][c2]:0);
    a+=max(max(cherryPickup_dp(r,grid,dp,r1,c1+1,c2+1), cherryPickup_dp(r,grid,dp,r1,c1+1,c2)), max(cherryPickup_dp(r,grid,dp,r1+1,c1,c2+1), cherryPickup_dp(r,grid,dp,r1+1,c1,c2)));
    dp[r1][c1][c2]=a;
    return a;
}
int cherryPickup(int** grid,int r,int* c){
    if(r==0)
        return 0;
    int dp[r][r][r];
    for(int i=0;i<r;i++)
        for(int j=0;j<r;j++)
            for(int k=0;k<r;k++)
                dp[i][j][k]=INT_MIN;
    return max(0,cherryPickup_dp(r,grid,dp,0,0,0));
}
