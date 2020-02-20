// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



// Given an integer n, return all distinct solutions to the n-queens puzzle.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

// Example:

// Input: 4
// Output: [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void solveNQueens_save(int n,int bamboo[n],char**** ra,int* rr,int** rc,int* nos){
    if(*nos==*rr){
        *nos+=1000;
        *ra=realloc(*ra,*nos*sizeof(char**));
    }
    (*ra)[*rr]=(char**)malloc(n*sizeof(char*));
    for(int i=0;i<n;i++)
        (*ra)[*rr][i]=(char*)malloc((n+1)*sizeof(char));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(bamboo[j]-1==i)
                (*ra)[*rr][i][j]='Q';
            else
                (*ra)[*rr][i][j]='.';
        }
        (*ra)[*rr][i][n]=NULL;
    }
    (*rr)++;
}
void solveNQueens_dfs(int n,int bamboo[n],bool slash[2*n-1],bool backslash[2*n-1],char**** ra,int* rr,int** rc,int row,int* nos){
    if(row==n){
        solveNQueens_save(n,bamboo,ra,rr,rc,nos);
        return;
    }
    for(int i=0;i<n;i++){
        if(bamboo[i]>0 || slash[row+i] || backslash[row-i+n-1])
            continue;
        bamboo[i]=row+1;
        slash[row+i]=true;
        backslash[row-i+n-1]=true;
        solveNQueens_dfs(n,bamboo,slash,backslash,ra,rr,rc,row+1,nos);
        backslash[row-i+n-1]=false;
        slash[row+i]=false;
        bamboo[i]=0;
    }
}
char*** solveNQueens(int n,int* rr,int** rc){
    int nos=1000;
    char*** ra=malloc(nos*sizeof(char**));
    int bamboo[n];
    bool slash[2*n-1],backslash[2*n-1];
    memset(bamboo,0,sizeof(bamboo));
    memset(slash,false,sizeof(slash));
    memset(backslash,false,sizeof(backslash));
    *rr=0;
    solveNQueens_dfs(n,bamboo,slash,backslash,&ra,rr,rc,0,&nos);
    *rc=(int*)malloc((*rr)*sizeof(int));
    for(int i=0;i<*rr;i++)
        (*rc)[i]=n;
    return ra;
}
