// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return the minimum cuts needed for a palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
// Example 2:

// Input: s = "a"
// Output: 0
// Example 3:

// Input: s = "ab"
// Output: 1
 

// Constraints:

// 1 <= s.length <= 2000
// s consists of lower-case English letters only.

class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        int dp[n];
        for(int i=0;i<n;++i)
            dp[i]=i;
        for(int i=0;i<n;++i){
            int j=i,k=i;
            while(j>=0 && k<n && s[j]==s[k]){
                dp[k]=min(dp[k],(j>0)?1+dp[j-1]:0);
                --j;
                ++k;
            }
            j=i;
            k=i+1;
            while(j>=0 && k<n && s[j]==s[k]){
                dp[k]=min(dp[k],(j>0)?1+dp[j-1]:0);
                --j;
                ++k;
            }
        }
        return dp[n-1];
    }
};
