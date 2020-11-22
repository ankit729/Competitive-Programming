// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

 

// Example 1:


// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:


 

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.

class Solution {
public:
    bool r[9][9]={},c[9][9]={},b[9][9]={};
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;++i)
            for(int j=0;j<9;++j)
                if(board[i][j]!='.'){
                    int num=board[i][j]-'1';
                    r[i][num]=true;
                    c[j][num]=true;
                    b[(i/3)*3+j/3][num]=true;
                }
        vector<pair<int,pair<int,int>>> pos;
        for(int i=0;i<9;++i)
            for(int j=0;j<9;++j)
                if(board[i][j]=='.'){
                    int box=(i/3)*3+j/3;
                    int count=0;
                    for(int k=0;k<9;k++)
                        count+=!r[i][k] && !c[j][k] && !b[box][k];
                    pos.push_back({count,{i,j}});
                }
        sort(pos.begin(),pos.end());
        solveSudokuDFS(board,pos,0);
    }
private:
    bool solveSudokuDFS(vector<vector<char>>& board, vector<pair<int,pair<int,int>>>& pos, int p) {
        if(p>=pos.size())
            return true;
        int i=pos[p].second.first;
        int j=pos[p].second.second;
        int box=(i/3)*3+j/3;
        for(int k=0;k<9;k++)
            if(!r[i][k] && !c[j][k] && !b[box][k]){
                board[i][j]=k+'1';
                r[i][k]=c[j][k]=b[box][k]=true;
                if(solveSudokuDFS(board,pos,p+1))
                    return true;
                r[i][k]=c[j][k]=b[box][k]=false;
                board[i][j]='.';
            }
        return false;
    }
};
