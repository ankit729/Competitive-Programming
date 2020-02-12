// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input:
// 11110
// 11010
// 11000
// 00000

// Output: 1
// Example 2:

// Input:
// 11000
// 11000
// 00100
// 00011

// Output: 3

void dfs(char** grid,int gr,int* gc,bool seen[gr][gc[0]],int dir[4][2],int i,int j){
    if(i<0||i==gr||j<0||j==gc[0])
        return;
    if(grid[i][j]=='0')
        return;
    if(seen[i][j])
        return;
    seen[i][j]=true;
    for(int k=0;k<4;k++)
        dfs(grid,gr,gc,seen,dir,i+dir[k][0],j+dir[k][1]);
}
int numIslands(char** grid,int gr,int* gc){
    if(gr==0||gc[0]==0)
        return 0;
    int ans=0;
    bool seen[gr][gc[0]];
    memset(seen,false,sizeof(seen));
    int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    for(int i=0;i<gr;i++)
        for(int j=0;j<gc[i];j++)
            if(grid[i][j]=='1' && !seen[i][j]){
                dfs(grid,gr,gc,seen,dir,i,j);
                ans++;
            }
    return ans;
}
