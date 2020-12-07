// In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

// Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

// Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)

 

// Example 1:

// Input: A = [[0,1],[1,0]]
// Output: 1
// Example 2:

// Input: A = [[0,1,0],[0,0,0],[0,0,1]]
// Output: 2
// Example 3:

// Input: A = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
// Output: 1
 

// Constraints:

// 2 <= A.length == A[0].length <= 100
// A[i][j] == 0 or A[i][j] == 1

class Solution {
    #define pii pair<int,int>
public:
    int shortestBridge(vector<vector<int>>& g) {
        n=g.size();
        queue<pii> q;
        for(int r=0;r<n;++r){
            for(int c=0;c<n;++c){
                if(g[r][c]==1){
                    fill(g,r,c,q);
                    
                    //out of loop
                    r=n;
                    break;
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first,c=q.front().second;
            q.pop();
            for(int i=0;i<4;++i){
                int nr=r+dir[i][0],nc=c+dir[i][1];
                if(valid(nr,nc)){
                    if(g[nr][nc]==1)
                        return g[r][c]-2;
                    if(g[nr][nc]==0){
                        g[nr][nc]=g[r][c]+1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return 0;
    }
private:
    int n;
    int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    bool valid(int r, int c) {
        return r>=0 && r<n && c>=0 && c<n;
    }
    void fill(vector<vector<int>>& g, int r, int c, queue<pii>& q) {
        q.push({r,c});
        g[r][c]=2;
        for(int i=0;i<4;++i){
            int nr=r+dir[i][0];
            int nc=c+dir[i][1];
            if(valid(nr,nc) && g[nr][nc]==1)
                fill(g,nr,nc,q);
        }
    }
};
auto fastIO=[](){std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
