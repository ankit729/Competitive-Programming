// Given an m x n board of characters and a list of strings words, return all words on the board.

// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

// Example 1:


// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
// Output: ["eat","oath"]
// Example 2:


// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []
 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 12
// board[i][j] is a lowercase English letter.
// 1 <= words.length <= 3 * 10^4
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// All the strings of words are unique.

class Solution {
public:
    vector<vector<char>> board;
    string word;
    int R,C,wL;
    vector<string> findWords(vector<vector<char>>& grid, vector<string>& s) {
        board=grid;
        R=board.size();
        C=board[0].size();
        vector<string> ans;
        for(string ss:s)
            if(exist(ss))
                ans.push_back(ss);
        return ans;
    }
private:
    bool exist(string& s) {
        word=s;
        wL=word.length();
        for(int i=0;i<R;++i)
            for(int j=0;j<C;++j)
                if(dfs(0,i,j))
                    return true;
        return false;
    }
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
