// Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

 

// Example 1:


// Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
// Output: 4
// Explanation: After the rain, water is trapped between the blocks.
// We have two small pounds 1 and 3 units trapped.
// The total volume of water trapped is 4.
// Example 2:


// Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
// Output: 10
 

// Constraints:

// m == heightMap.length
// n == heightMap[i].length
// 1 <= m, n <= 200
// 0 <= heightMap[i][j] <= 2 * 10^4

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int R=heightMap.size(),C=heightMap[0].size(),ans=0;
        auto compare=[&heightMap](auto& a, auto& b) {
            return heightMap[a.first][a.second]>heightMap[b.first][b.second];
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(compare)> pq(compare);
        bool visited[R][C];
        memset(visited,false,sizeof(visited));
        int count=R*C;
        for(int r=0;r<R;++r){
            pq.push({r,0});
            pq.push({r,C-1});
            visited[r][0]=visited[r][C-1]=true;
            count-=2;
        }
        for(int c=1;c<C-1;++c){
            pq.push({0,c});
            pq.push({R-1,c});
            visited[0][c]=visited[R-1][c]=true;
            count-=2;
        }
        int dir[]={-1,0,1,0,-1};
        while(count>0){
            auto [r,c]=pq.top();
            pq.pop();
            for(int i=0;i<4;++i){
                int nr=r+dir[i],nc=c+dir[i+1];
                if(nr>=0 && nr<R && nc>=0 && nc<C && !visited[nr][nc]){
                    if(heightMap[nr][nc]<heightMap[r][c]){
                        ans+=heightMap[r][c]-heightMap[nr][nc];
                        heightMap[nr][nc]=heightMap[r][c];
                    }
                    visited[nr][nc]=true;
                    pq.push({nr,nc});
                    count--;
                }
            }
        }
        return ans;
    }
};
