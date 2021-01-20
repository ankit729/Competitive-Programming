// You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

// Return the number of servers that communicate with any other server.

 

// Example 1:



// Input: grid = [[1,0],[0,1]]
// Output: 0
// Explanation: No servers can communicate with others.
// Example 2:



// Input: grid = [[1,0],[1,1]]
// Output: 3
// Explanation: All three servers can communicate with at least one other server.
// Example 3:



// Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
// Output: 4
// Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m <= 250
// 1 <= n <= 250
// grid[i][j] == 0 or 1

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int R=grid.size(),C=(R>0)?grid[0].size():0,ans=0;
        int row[R],col[C];
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for(int r=0;r<R;++r)
            for(int c=0;c<C;++c)
                if(grid[r][c])
                    row[r]++,col[c]++;
        for(int r=0;r<R;++r)
            for(int c=0;c<C;++c)
                if(grid[r][c] && (row[r]>=2 || col[c]>=2))
                    ans++;
        return ans;
    }
};
