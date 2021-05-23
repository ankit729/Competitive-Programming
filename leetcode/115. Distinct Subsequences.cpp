// Given two strings s and t, return the number of distinct subsequences of s which equals t.

// A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

// It is guaranteed the answer fits on a 32-bit signed integer.

 

// Example 1:

// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from S.
// rabbbit
// rabbbit
// rabbbit
// Example 2:

// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from S.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag
 

// Constraints:

// 1 <= s.length, t.length <= 1000
// s and t consist of English letters.

class Solution {
public:
    int numDistinct(string s, string t) {
        int ns=s.length(),nt=t.length();
        if(ns<=nt)
            return s==t;
        unsigned int dp[nt+1];
        fill(dp,dp+nt,0);
        dp[nt]=1;
        for(int is=ns-1;is>=0;--is){
            for(int it=min(nt-1,is),prev=dp[it+1];it>=0;--it){
                int temp=dp[it];
                if(s[is]==t[it])
                    dp[it]+=prev;
                prev=temp;
            }
        }
        return dp[0];
    }
};
