// There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.

 

// Example 1:

// Input: m = 2, n = 2, N = 2, i = 0, j = 0
// Output: 6
// Explanation:

// Example 2:

// Input: m = 1, n = 3, N = 3, i = 0, j = 1
// Output: 12
// Explanation:

 

// Note:

// Once you move the ball out of boundary, you cannot move it back.
// The length and height of the grid is in range [1,50].
// N is in range [0,50].

void findPaths_add(int* a,int* b,int MOD){
    *a+=*b;
    if(*a>=MOD)
        *a-=MOD;
}
int findPaths(int m,int n,int N,int sr,int sc){
    if(sr<0 || sr>=m || sc<0 || sc>=n || N==0)
        return 0;
    int MOD=1000000007;
    int dp[m][n][N];
    memset(dp,0,sizeof(dp));
    dp[sr][sc][0]=1;
    int dirr[4]={-1,0,1,0};
    int dirc[4]={0,1,0,-1};
    for(int k=1;k<N;k++)
        for(int r=0;r<m;r++)
            for(int c=0;c<n;c++)
                if(dp[r][c][k-1]>0)
                    for(int d=0;d<4;d++){
                        int nr=r+dirr[d];
                        int nc=c+dirc[d];
                        if(nr>=0 && nr<m && nc>=0 && nc<n)
                            findPaths_add(&dp[nr][nc][k],&dp[r][c][k-1],MOD);
                    }
    int ans=0;
    for(int k=0;k<N;k++){
        for(int i=0;i<n;i++)
            findPaths_add(&ans,&dp[0][i][k],MOD);
        for(int i=0;i<m;i++)
            findPaths_add(&ans,&dp[i][n-1][k],MOD);
        for(int i=n-1;i>=0;i--)
            findPaths_add(&ans,&dp[m-1][i][k],MOD);
        for(int i=m-1;i>=0;i--)
            findPaths_add(&ans,&dp[i][0][k],MOD);
    }
    return ans;
}
