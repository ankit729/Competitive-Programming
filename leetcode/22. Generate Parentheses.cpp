// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

// Constraints:

// 1 <= n <= 8

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        dp[0]={""};
        for(int i=1;i<=n;++i)
            for(int l=0,r=i-1;l<i;++l,--r)
                for(string& left:dp[l])
                    for(string& right:dp[r])
                        dp[i].push_back("("+left+")"+right);
        return dp[n];
    }
};
