// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

// Example:

// Input: 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]

void totalNQueens_dfs(int n,int bamboo[n],bool slash[2*n-1],bool backslash[2*n-1],int row,int* ans){
    if(row==n){
        (*ans)++;
        return;
    }
    for(int i=0;i<n;i++){
        if(bamboo[i]>0 || slash[row+i] || backslash[row-i+n-1])
            continue;
        bamboo[i]=row+1;
        slash[row+i]=true;
        backslash[row-i+n-1]=true;
        totalNQueens_dfs(n,bamboo,slash,backslash,row+1,ans);
        backslash[row-i+n-1]=false;
        slash[row+i]=false;
        bamboo[i]=0;
    }
}
int totalNQueens(int n){
    int ans=0;
    int bamboo[n];
    bool slash[2*n-1],backslash[2*n-1];
    memset(bamboo,0,sizeof(bamboo));
    memset(slash,false,sizeof(slash));
    memset(backslash,false,sizeof(backslash));
    totalNQueens_dfs(n,bamboo,slash,backslash,0,&ans);
    return ans;
}
