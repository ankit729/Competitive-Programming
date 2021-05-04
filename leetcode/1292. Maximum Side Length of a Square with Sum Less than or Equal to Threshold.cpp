// Given a m x n matrix mat and an integer threshold. Return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.

 

// Example 1:


// Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
// Output: 2
// Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
// Example 2:

// Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
// Output: 0
// Example 3:

// Input: mat = [[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]], threshold = 6
// Output: 3
// Example 4:

// Input: mat = [[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]], threshold = 40184
// Output: 2
 

// Constraints:

// 1 <= m, n <= 300
// m == mat.length
// n == mat[i].length
// 0 <= mat[i][j] <= 10000
// 0 <= threshold <= 10^5

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int R=mat.size(),C=(R>0)?mat[0].size():0,ans=0;
        for(int r=0;r<R;++r){
            for(int c=0;c<C;++c){
                if(r>0)
                    mat[r][c]+=mat[r-1][c];
                if(c>0)
                    mat[r][c]+=mat[r][c-1];
                if(r>0 && c>0)
                    mat[r][c]-=mat[r-1][c-1];
                for(int rl=r-ans,cl=c-ans;rl>=0 && cl>=0;--rl,--cl){
                    int sum=mat[r][c];
                    if(rl>0)
                        sum-=mat[rl-1][c];
                    if(cl>0)
                        sum-=mat[r][cl-1];
                    if(rl>0 && cl>0)
                        sum+=mat[rl-1][cl-1];
                    if(sum<=threshold)
                        ans++;
                    else
                        break;
                }
            }
        }
        return ans;
    }
};
