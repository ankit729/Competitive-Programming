// Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

// The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

 

// Example 1:


// Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
// Output: 2
// Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
// Example 2:


// Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
// Output: 4
// Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
 

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int R=grid.size(),C=grid[0].size(),ans=0;
        int MAX=R+C;
        for(int r=0;r<R;++r){
            for(int c=0;c<C;++c){
                if(grid[r][c]==1)
                    continue;
                grid[r][c]=MAX;
                if(r>0)
                    grid[r][c]=min(grid[r][c],grid[r-1][c]+1);
                if(c>0)
                    grid[r][c]=min(grid[r][c],grid[r][c-1]+1);
            }
        }
        for(int r=R-1;r>=0;--r){
            for(int c=C-1;c>=0;--c){
                if(grid[r][c]==1)
                    continue;
                if(r+1<R)
                    grid[r][c]=min(grid[r][c],grid[r+1][c]+1);
                if(c+1<C)
                    grid[r][c]=min(grid[r][c],grid[r][c+1]+1);
                ans=max(ans,grid[r][c]);
            }
        }
        return ans==MAX?-1:ans-1;
    }
};
