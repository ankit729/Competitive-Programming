// Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.

 

// Example 1:

// Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
// Output: 9
// Example 2:

// Input: grid = [[1,1,0,0]]
// Output: 1
 

// Constraints:

// 1 <= grid.length <= 100
// 1 <= grid[0].length <= 100
// grid[i][j] is 0 or 1

int min(int a,int b){
    return (a<b)?a:b;
}
int max(int a,int b){
    return (a>b)?a:b;
}
int largest1BorderedSquare(int** grid,int r,int* c){
    int dp[r+1][c[0]+1][2],ans=0;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c[i-1];j++)
            if(grid[i-1][j-1]){
                dp[i][j][0]=dp[i][j-1][0]+1;
                dp[i][j][1]=dp[i-1][j][1]+1;
                int k=min(dp[i][j][0],dp[i][j][1])-1;
                if(k+1>ans)
                    for(;k>=0;k--)
                        if(dp[i-k][j][0]>k && dp[i][j-k][1]>k)
                            ans=max(ans,k+1);
            }
    return ans*ans;
}
