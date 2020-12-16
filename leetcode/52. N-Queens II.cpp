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

class Solution {
public:
    int totalNQueens(int n) {
        int ans=0;
        bool bamboo[n],slash[(n<<1)-1],backslash[(n<<1)-1];
        memset(bamboo,false,sizeof(bamboo));
        memset(slash,false,sizeof(slash));
        memset(backslash,false,sizeof(backslash));
        dfs(n,bamboo,slash,backslash,0,ans);
        return ans;
    }
private:
    void dfs(int n, bool* bamboo, bool* slash, bool* backslash, int r, int& ans) {
        if(r==n){
            ans++;
            return;
        }
        for(int i=0;i<n;++i){
            if(bamboo[i] || slash[r+i] || backslash[r-i+n-1])
                continue;
            bamboo[i]=true;
            slash[r+i]=true;
            backslash[r-i+n-1]=true;
            dfs(n,bamboo,slash,backslash,r+1,ans);
            backslash[r-i+n-1]=false;
            slash[r+i]=false;
            bamboo[i]=false;
        }
    }
};
