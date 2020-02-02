// On a 2-dimensional grid, there are 4 types of squares:

// 1 represents the starting square.  There is exactly one starting square.
// 2 represents the ending square.  There is exactly one ending square.
// 0 represents empty squares we can walk over.
// -1 represents obstacles that we cannot walk over.
// Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

// Example 1:

// Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
// Output: 2
// Explanation: We have the following two paths: 
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
// 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
// Example 2:

// Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
// Output: 4
// Explanation: We have the following four paths: 
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
// 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
// 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
// 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
// Example 3:

// Input: [[0,1],[2,0]]
// Output: 0
// Explanation: 
// There is no path that walks over every empty square exactly once.
// Note that the starting and ending square can be anywhere in the grid.
 

// Note:

// 1 <= grid.length * grid[0].length <= 20

int uniquePathsIII_dfs(int r,int* c,int** grid,bool seen[r][c[0]],int dir[4][2],int i,int j,int value){
    if(i<0 || i>=r || j<0 || j>=c[0])
        return 0;
    if(grid[i][j]==-1)
        return 0;
    if(grid[i][j]==2)
        return (value==0)?1:0;
    if(!seen[i][j]){
        seen[i][j]=true;
        int a=0;
        for(int k=0;k<4;k++)
            a+=uniquePathsIII_dfs(r,c,grid,seen,dir,i+dir[k][0],j+dir[k][1],value-1);
        seen[i][j]=false;
        return a;
    }
    return 0;
}
int uniquePathsIII(int** grid, int r, int* c){
    bool seen[r][c[0]];
    memset(seen,false,sizeof(seen));
    int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    int value=r*c[0];
    for(int i=0;i<r;i++)
        for(int j=0;j<c[i];j++)
            if(grid[i][j]==-1 || grid[i][j]==2)
                value--;
    for(int i=0;i<r;i++)
        for(int j=0;j<c[i];j++)
            if(grid[i][j]==1)
                return uniquePathsIII_dfs(r,c,grid,seen,dir,i,j,value);
    return 0;
}
