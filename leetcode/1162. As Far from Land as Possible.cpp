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
    int dir[5]={-1,0,1,0,-1};
public:
    int maxDistance(vector<vector<int>>& grid) {
        int R=grid.size(),C=grid[0].size(),ans=0;
        queue<pair<int,int>> q;
        for(int r=0;r<R;++r)
            for(int c=0;c<C;++c){
                if(grid[r][c])
                    q.push({r,c}),grid[r][c]=0;
                else
                    grid[r][c]=INT_MAX;
            }
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [r,c]=q.front();
                q.pop();
                for(int i=0;i<4;++i){
                    int nr=r+dir[i],nc=c+dir[i+1];
                    if(nr>=0 && nr<R && nc>=0 && nc<C && grid[nr][nc]>grid[r][c]+1)
                        grid[nr][nc]=grid[r][c]+1,q.push({nr,nc});
                }
            }
            ans++;
        }
        return (ans==1)?-1:ans-1;
    }
};
