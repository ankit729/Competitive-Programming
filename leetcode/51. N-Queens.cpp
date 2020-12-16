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

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> base(n,string(n,'.'));
        bool bamboo[n],slash[(n<<1)-1],backslash[(n<<1)-1];
        memset(bamboo,false,sizeof(bamboo));
        memset(slash,false,sizeof(slash));
        memset(backslash,false,sizeof(backslash));
        dfs(n,base,bamboo,slash,backslash,0,ans);
        return ans;
    }
private:
    void dfs(int n, vector<string>& base, bool* bamboo, bool* slash, bool* backslash, int r, vector<vector<string>>& ans) {
        if(r==n){
            ans.push_back(base);
            return;
        }
        for(int i=0;i<n;++i){
            if(bamboo[i] || slash[r+i] || backslash[r-i+n-1])
                continue;
            bamboo[i]=true;
            slash[r+i]=true;
            backslash[r-i+n-1]=true;
            base[r][i]='Q';
            dfs(n,base,bamboo,slash,backslash,r+1,ans);
            base[r][i]='.';
            backslash[r-i+n-1]=false;
            slash[r+i]=false;
            bamboo[i]=false;
        }
    }
};
