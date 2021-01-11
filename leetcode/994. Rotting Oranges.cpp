// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:


// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.

class Solution {
public:
    int orangesRotting(vector<vector<int>> grid) {
        int R=grid.size(),C=grid[0].size(),ans=0;
        int d[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        queue<pair<int,int>> q;
        for(int r=0;r<R;++r)
            for(int c=0;c<C;++c)
                if(grid[r][c]==2)
                    q.push({r,c});
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto [r,c]=q.front();
                q.pop();
                for(int i=0;i<4;++i){
                    int nr=r+d[i][0],nc=c+d[i][1];
                    if(valid(nr,nc,R,C) && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                    }
                }
            }
            ans++;
        }
        for(int r=0;r<R;++r)
            for(int c=0;c<C;++c)
                if(grid[r][c]==1)
                    return -1;
        return (ans==0)?ans:ans-1;
    }
private:
    bool valid(int r, int c, int R, int C) {
        return r>=0 && r<R && c>=0 && c<C;
    }
};
