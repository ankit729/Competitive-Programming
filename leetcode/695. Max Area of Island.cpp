// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.

 

// Example 1:


// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.
// Example 2:

// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// grid[i][j] is either 0 or 1.

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int R=grid.size(),C=grid[0].size(),ans=0;
        vector<vector<bool>> visited(R,vector<bool>(C));
        int dir[5]={-1,0,1,0,-1};
        for(int r=0;r<R;++r){
            for(int c=0;c<C;++c){
                if(grid[r][c]==1 && !visited[r][c]){
                    stack<pair<int,int>> stk;
                    stk.push({r,c});
                    visited[r][c]=true;
                    int temp=0;
                    while(!stk.empty()){
                        auto [r,c]=stk.top();stk.pop();
                        temp++;
                        for(int i=0;i<4;++i){
                            int nr=r+dir[i],nc=c+dir[i+1];
                            if(nr>=0 && nr<R && nc>=0 && nc<C && grid[nr][nc]==1 && !visited[nr][nc]){
                                visited[nr][nc]=true;
                                stk.push({nr,nc});
                            }
                        }
                    }
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};
