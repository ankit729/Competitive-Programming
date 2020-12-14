// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// A palindrome string is a string that reads the same backward as forward.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]
 

// Constraints:

// 1 <= s.length <= 16
// s contains only lowercase English letters.

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<string>> ans;
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        vector<int> p[n];
        for(int len=1;len<=n;++len){
            for(int l=0,r=len-1;r<n;++l,++r){
                if(s[l]==s[r] && (r-l+1<=3 || dp[l+1][r-1])){
                    dp[l][r]=true;
                    p[l].push_back(r);
                }
            }
        }
        vector<string> curr;
        dfs(s,n,0,p,ans,curr);
        return ans;
    }
private:
    void dfs(string& s, int n, int l, vector<int>* p, vector<vector<string>>& ans, vector<string>& curr) {
        if(l>=n){
            ans.push_back(curr);
            return;
        }
        curr.push_back("");
        int left=l;
        for(auto& r:p[l]){
            curr.back()+=s.substr(left,r-left+1);
            dfs(s,n,r+1,p,ans,curr);
            left=r+1;
        }
        curr.pop_back();
    }
};
