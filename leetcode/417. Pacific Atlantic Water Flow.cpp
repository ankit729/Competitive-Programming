// You are given an m x n integer matrix heights representing the height of each unit cell in a continent. The Pacific ocean touches the continent's left and top edges, and the Atlantic ocean touches the continent's right and bottom edges.

// Water can only flow in four directions: up, down, left, and right. Water flows from a cell to an adjacent one with an equal or lower height.

// Return a list of grid coordinates where water can flow to both the Pacific and Atlantic oceans.

 

// Example 1:


// Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
// Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
// Example 2:

// Input: heights = [[2,1],[1,2]]
// Output: [[0,0],[0,1],[1,0],[1,1]]
 

// Constraints:

// m == heights.length
// n == heights[i].length
// 1 <= m, n <= 200
// 1 <= heights[i][j] <= 10^5

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int R=matrix.size(),C=(R>0)?matrix[0].size():0;
        vector<vector<int>> ans;
        if(R==0 || C==0)
            return ans;
        vector<vector<bool>> pacific(R,vector<bool>(C,false));
        vector<vector<bool>> atlantic=pacific;
        queue<pair<int,int>> q;
        for(int i=0;i<R;++i)
            pacific[i][0]=true,q.push({i,0});
        for(int i=1;i<C;++i)
            pacific[0][i]=true,q.push({0,i});
        helper(matrix,pacific,R,C,q);
        for(int i=0;i<R;++i)
            atlantic[i][C-1]=true,q.push({i,C-1});
        for(int i=1;i<C;++i)
            atlantic[R-1][i-1]=true,q.push({R-1,i-1});
        helper(matrix,atlantic,R,C,q);
        for(int r=0;r<R;++r)
            for(int c=0;c<C;++c)
                if(pacific[r][c] && atlantic[r][c])
                    ans.push_back({r,c});
        return ans;
    }
private:
    int dir[5]={-1,0,1,0,-1};
    void helper(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int R, int C, queue<pair<int,int>>& q) {
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;++i){
                int nr=r+dir[i],nc=c+dir[i+1];
                if(nr>=0 && nr<R && nc>=0 && nc<C && !visited[nr][nc] && matrix[nr][nc]>=matrix[r][c])
                    visited[nr][nc]=true,q.push({nr,nc});
            }
        }
    }
};
