// Given a m x n binary matrix mat. In one step, you can choose one cell and flip it and all the four neighbours of it if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighboors if they share one edge.

// Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.

// Binary matrix is a matrix with all cells equal to 0 or 1 only.

// Zero matrix is a matrix with all cells equal to 0.

 

// Example 1:


// Input: mat = [[0,0],[0,1]]
// Output: 3
// Explanation: One possible solution is to flip (1, 0) then (0, 1) and finally (1, 1) as shown.
// Example 2:

// Input: mat = [[0]]
// Output: 0
// Explanation: Given matrix is a zero matrix. We don't need to change it.
// Example 3:

// Input: mat = [[1,1,1],[1,0,1],[0,0,0]]
// Output: 6
// Example 4:

// Input: mat = [[1,0,0],[1,0,0]]
// Output: -1
// Explanation: Given matrix can't be a zero matrix
 

// Constraints:

// m == mat.length
// n == mat[0].length
// 1 <= m <= 3
// 1 <= n <= 3
// mat[i][j] is 0 or 1.

class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int R=mat.size(),C=mat[0].size(),ans=0;
        int bitvec=0;
        for(int r=R-1;r>=0;--r){
            for(int c=C-1;c>=0;--c){
                bitvec<<=1;
                bitvec|=mat[r][c];
            }
        }
        unordered_set<int> st;
        queue<int> q;
        q.push(bitvec);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                bitvec=q.front();
                q.pop();
                if(!bitvec)
                    return ans;
                for(int r=0;r<R;++r){
                    for(int c=0;c<C;++c){
                        int temp=flip(bitvec,R,C,r,c);
                        if(!st.count(temp))
                            q.push(temp),st.insert(temp);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
private:
    int dir[5]={-1,0,1,0,-1};
    int flip(int bitvec, int R, int C, int r, int c) {
        bitvec^=(1<<(r*C+c));
        for(int i=0;i<4;++i){
            int nr=r+dir[i],nc=c+dir[i+1];
            if(nr>=0 && nr<R && nc>=0 && nc<C)
                bitvec^=(1<<(nr*C+nc));
        }
        return bitvec;
    }
};
