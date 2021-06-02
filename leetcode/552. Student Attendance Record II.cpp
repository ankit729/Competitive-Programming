// An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

// 'A': Absent.
// 'L': Late.
// 'P': Present.
// Any student is eligible for an attendance award if they meet both of the following criteria:

// The student was absent ('A') for strictly fewer than 2 days total.
// The student was never late ('L') for 3 or more consecutive days.
// Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 10^9 + 7.

 

// Example 1:

// Input: n = 2
// Output: 8
// Explanation: There are 8 records with length 2 that are eligible for an award:
// "PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
// Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).
// Example 2:

// Input: n = 1
// Output: 3
// Example 3:

// Input: n = 10101
// Output: 183236316
 

// Constraints:

// 1 <= n <= 10^5

const int MOD=1e9+7;
class Solution {
public:
    int checkRecord(int n) {
        int ans=0;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;++i)
            dp[i]=(0LL+dp[i-1]+dp[i-2]+(i>=3?dp[i-3]:0))%MOD;
        for(int i=n;i>=2;--i)
            dp[i]=(0LL+dp[i]+dp[i-1]+dp[i-2])%MOD;
        dp[1]++;
        for(int i=1;i<=n;++i)
            ans=(ans+1LL*dp[i-1]*dp[n-i])%MOD;
        return (ans+dp[n])%MOD;
    }
};
