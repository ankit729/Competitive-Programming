// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = []
// Output: 0
// Example 3:

// Input: matrix = [["0"]]
// Output: 0
// Example 4:

// Input: matrix = [["1"]]
// Output: 1
// Example 5:

// Input: matrix = [["0","0"]]
// Output: 0
 

// Constraints:

// rows == matrix.length
// cols == matrix[i].length
// 0 <= row, cols <= 200
// matrix[i][j] is '0' or '1'.

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int R=mat.size(),C=R>0?mat[0].size():0,ans=0;
        if(C==0)
            return 0;
        int dp[C];
        fill(dp,dp+C,0);
        for(int r=0;r<R;++r){
            for(int c=0;c<C;++c)
                dp[c]=mat[r][c]-'0'?dp[c]+1:0;
            ans=max(ans,largestRectangleArea(dp,C));
        }
        return ans;
    }
private:
    int largestRectangleArea(int* dp, int n) {
        int ans=0;
        stack<int> stk;
        int i=0;
        while(i<n){
            while(!stk.empty() && dp[i]<=dp[stk.top()]){
                int curr=dp[stk.top()];
                stk.pop();
                ans=max(ans,curr*(stk.empty()?i:i-stk.top()-1));
            }
            stk.push(i++);
        }
        while(!stk.empty()){
            int curr=dp[stk.top()];
            stk.pop();
            ans=max(ans,curr*(stk.empty()?i:i-stk.top()-1));
        }
        return ans;
    }
};
