// You are given a grid of size N x N, and each cell of this grid has a lamp that is initially turned off.

// You are also given an array of lamp positions lamps, where lamps[i] = [rowi, coli] indicates that the lamp at grid[rowi][coli] is turned on. When a lamp is turned on, it illuminates its cell and all other cells in the same row, column, or diagonal.

// Finally, you are given a query array queries, where queries[i] = [rowi, coli]. For the ith query, determine whether grid[rowi][coli] is illuminated or not. After answering the ith query, turn off the lamp at grid[rowi][coli] and its 8 adjacent lamps if they exist. A lamp is adjacent if its cell shares either a side or corner with grid[rowi][coli].

// Return an array of integers ans, where ans[i] should be 1 if the lamp in the ith query was illuminated, or 0 if the lamp was not.

 

// Example 1:


// Input: N = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
// Output: [1,0]
// Explanation: We have the initial grid with all lamps turned off. In the above picture we see the grid after turning on the lamp at grid[0][0] then turning on the lamp at grid[4][4].
// The 0th query asks if the lamp at grid[1][1] is illuminated or not (the blue square). It is illuminated, so set ans[0] = 1. Then, we turn off all lamps in the red square.

// The 1st query asks if the lamp at grid[1][0] is illuminated or not (the blue square). It is not illuminated, so set ans[1] = 1. Then, we turn off all lamps in the red rectangle.

// Example 2:

// Input: N = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,1]]
// Output: [1,1]
// Example 3:

// Input: N = 5, lamps = [[0,0],[0,4]], queries = [[0,4],[0,1],[1,4]]
// Output: [1,1,0]
 

// Constraints:

// 1 <= N <= 10^9
// 0 <= lamps.length <= 20000
// lamps[i].length == 2
// 0 <= lamps[i][j] < N
// 0 <= queries.length <= 20000
// queries[i].length == 2
// 0 <= queries[i][j] < N

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);cin.tie(NULL);
    }
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        int ln=lamps.size(),qn=queries.size();
        unordered_map<int,int> row,col,slash,backslash;
        set<pair<int,int>> lamp;
        vector<int> ans;
        for(int k=0;k<ln;++k){
            int r=lamps[k][0],c=lamps[k][1];
            row[r]++;
            col[c]++;
            slash[r+c]++;
            backslash[r+N-1-c]++;
            lamp.insert({r,c});
        }
        for(int k=0;k<qn;++k){
            int r=queries[k][0],c=queries[k][1];
            ans.push_back(row.find(r)!=row.end() || col.find(c)!=col.end() || slash.find(r+c)!=slash.end() || backslash.find(r+N-1-c)!=backslash.end());
            for(int nr=r-1;nr<=r+1;++nr){
                for(int nc=c-1;nc<=c+1;++nc){
                    auto it=lamp.find({nr,nc});
                    if(it==lamp.end())
                        continue;
                    lamp.erase(it);
                    modify(nr,row);
                    modify(nc,col);
                    modify(nr+nc,slash);
                    modify(nr+N-1-nc,backslash);
                }
            }
        }
        return ans;
    }
private:
    void modify(int key, unordered_map<int,int>& mp) {
        mp[key]--;
        if(mp[key]==0)
            mp.erase(key);
    }
};
