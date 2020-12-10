// You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colours: Red, Yellow or Green while making sure that no two adjacent cells have the same colour (i.e no two cells that share vertical or horizontal sides have the same colour).

// You are given n the number of rows of the grid.

// Return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 10^9 + 7.

 

// Example 1:

// Input: n = 1
// Output: 12
// Explanation: There are 12 possible way to paint the grid as shown:

// Example 2:

// Input: n = 2
// Output: 54
// Example 3:

// Input: n = 3
// Output: 246
// Example 4:

// Input: n = 7
// Output: 106494
// Example 5:

// Input: n = 5000
// Output: 30228214
 

// Constraints:

// n == grid.length
// grid[i].length == 3
// 1 <= n <= 5000

class Solution {
    typedef long long int ll;
public:
    int numOfWays(int n) {
        vector<vector<ll>> ans={{6,6}},M={{3,2},{2,2}};
        for(--n;n;n>>=1,M=mul(M,M))
            if(n&1)
                ans=mul(ans,M);
        return (ans[0][0]+ans[0][1])%MOD;
    }
private:
    int MOD=1e9+7;
    vector<vector<ll>> mul(vector<vector<ll>>& A, vector<vector<ll>>& B) {
        int n=A.size(),l=B.size(),m=B[0].size();
        vector<vector<ll>> C(n,vector<ll>(m,0));
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                for(int k=0;k<l;++k)
                    C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
        return C;
    }
};
