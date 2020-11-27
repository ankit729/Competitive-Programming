// Given an m x n board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

// Example 1:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
 

// Constraints:

// m == board.length
// n = board[i].length
// 1 <= m, n <= 200
// 1 <= word.length <= 10^3
// board and word consists only of lowercase and uppercase English letters.

class Solution {
public:
    vector<vector<char>> board;
    string word;
    int R,C,wL;
    bool exist(vector<vector<char>>& grid, string s) {
        board=grid;
        R=board.size();
        C=board[0].size();
        word=s;
        wL=word.length();
        for(int i=0;i<R;++i)
            for(int j=0;j<C;++j)
                if(dfs(0,i,j))
                    return true;
        return false;
    }
private:
    bool dfs(int index, int i, int j) {
        if(index==wL)
            return true;
        if(i<0 || i>=R || j<0 || j>=C || board[i][j]!=word[index])
            return false;
        char temp=board[i][j];
        board[i][j]='.';
        bool ans=dfs(index+1,i-1,j) || dfs(index+1,i,j+1) || dfs(index+1,i+1,j) || dfs(index+1,i,j-1);
        board[i][j]=temp;
        return ans;
    }
};
