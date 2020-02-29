// On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).

// A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

 



 

// Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

// The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.

 

// Example:

// Input: 3, 2, 0, 0
// Output: 0.0625
// Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
// From each of those positions, there are also two moves that will keep the knight on the board.
// The total probability the knight stays on the board is 0.0625.
 

// Note:

// N will be between 1 and 25.
// K will be between 0 and 100.
// The knight always initially starts on the board.

double knightProbability(int N,int K,int sr,int sc){
    double dp[N][N][K+1];
    memset(dp,0,sizeof(dp));
    dp[sr][sc][0]=1;
    int dirr[8]={-2,-2,-1,1,2,2,1,-1};
    int dirc[8]={-1,1,2,2,1,-1,-2,-2};
    for(int k=1;k<=K;k++)
        for(int r=0;r<N;r++)
            for(int c=0;c<N;c++)
                if(dp[r][c][k-1]>0)
                    for(int d=0;d<8;d++){
                        int nr=r+dirr[d];
                        int nc=c+dirc[d];
                        if(nr>=0 && nr<N && nc>=0 && nc<N)
                            dp[nr][nc][k]+=dp[r][c][k-1]/8;
                    }
    double ans=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            ans+=dp[i][j][K];
    return ans;
}
