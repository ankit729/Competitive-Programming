// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// Example:

// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:

// X X X X
// X X X X
// X X X X
// X O X X
// Explanation:

// Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

void solve_dfs(char** board,int br,int* bc,int dir[4][2],int i,int j){
    if(i<0||i>=br||j<0||j>=bc[0])
        return;
    if(board[i][j]!='O')
        return;
    board[i][j]='?';
    for(int k=0;k<4;k++)
        solve_dfs(board,br,bc,dir,i+dir[k][0],j+dir[k][1]);
}
void solve(char** board,int br,int* bc){
    if(br<=2||bc[0]<=2)
        return;
    int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    for(int i=0;i<br;i+=br-1)
        for(int j=0;j<bc[0];j++)
            if(board[i][j]=='O')
                solve_dfs(board,br,bc,dir,i,j);
    for(int i=0;i<br;i++)
        for(int j=0;j<bc[0];j+=bc[0]-1)
            if(board[i][j]=='O')
                solve_dfs(board,br,bc,dir,i,j);
    for(int i=0;i<br;i++)
        for(int j=0;j<bc[i];j++){
            if(board[i][j]=='?')
                board[i][j]='O';
            else
                board[i][j]='X';
        }
}
