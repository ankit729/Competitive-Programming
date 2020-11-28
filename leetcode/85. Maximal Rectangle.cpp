// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Example:

// Input:
// [
//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]
// ]
// Output: 6

class Solution {
public:
    vector<int> dp;
    int n;
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int r=matrix.size();
        if(matrix[0].empty())
            return 0;
        int c=matrix[0].size();
        int ans=0;
        n=c;
        dp.assign(n,0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                dp[j]=(matrix[i][j]-'0')?dp[j]+1:0;
            ans=max(ans,largestRectangleArea());
        }
        return ans;
    }
private:
    int largestRectangleArea() {
        int ans=0;
        stack<int> stack;
        int i=0;
        while(i<n){
            if(stack.empty() || dp[i]>dp[stack.top()]){
                stack.push(i++);
                continue;
            }
            while(!stack.empty() && dp[i]<dp[stack.top()]){
                int curr=dp[stack.top()];
                stack.pop();
                ans=max(ans,curr*(stack.empty()?i:i-stack.top()-1));
            }
            stack.push(i++);
        }
        while(!stack.empty()){
            int curr=dp[stack.top()];
            stack.pop();
            ans=max(ans,curr*(stack.empty()?i:i-stack.top()-1));
        }
        return ans;
    }
};
