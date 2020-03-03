// In a gold mine grid of size m * n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

// Return the maximum amount of gold you can collect under the conditions:

// Every time you are located in a cell you will collect all the gold in that cell.
// From your position you can walk one step to the left, right, up or down.
// You can't visit the same cell more than once.
// Never visit a cell with 0 gold.
// You can start and stop collecting gold from any position in the grid that has some gold.
 

// Example 1:

// Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
// Output: 24
// Explanation:
// [[0,6,0],
//  [5,8,7],
//  [0,9,0]]
// Path to get the maximum gold, 9 -> 8 -> 7.
// Example 2:

// Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
// Output: 28
// Explanation:
// [[1,0,7],
//  [2,0,6],
//  [3,4,5],
//  [0,3,0],
//  [9,0,20]]
// Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
 

// Constraints:

// 1 <= grid.length, grid[i].length <= 15
// 0 <= grid[i][j] <= 100
// There are at most 25 cells containing gold.

int max(int a,int b){
    return (a>b)?a:b;
}
int getMaximumGold_Util(int** grid,int gr,int* gc,int i,int j,int sum){
    if(i<0||i>=gr||j<0||j>=gc[0])
        return sum;
    if(grid[i][j]==0)
        return sum;
    sum+=grid[i][j];
    int temp=grid[i][j];
    grid[i][j]=0;
    int ans=0;
    ans=max(max(getMaximumGold_Util(grid,gr,gc,i-1,j,sum),getMaximumGold_Util(grid,gr,gc,i,j+1,sum)),max(getMaximumGold_Util(grid,gr,gc,i+1,j,sum),getMaximumGold_Util(grid,gr,gc,i,j-1,sum)));
    grid[i][j]=temp;
    return ans;
}
int getMaximumGold(int** grid,int gr,int* gc){
    int ans=0;
    for(int i=0;i<gr;i++)
        for(int j=0;j<gc[i];j++)
            if(grid[i][j]>0)
                ans=max(ans,getMaximumGold_Util(grid,gr,gc,i,j,0));
    return ans;
}
