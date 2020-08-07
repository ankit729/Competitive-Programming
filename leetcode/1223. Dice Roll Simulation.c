// A die simulator generates a random number from 1 to 6 for each roll. You introduced a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times. 

// Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained with exact n rolls.

// Two sequences are considered different if at least one element differs from each other. Since the answer may be too large, return it modulo 10^9 + 7.

 

// Example 1:

// Input: n = 2, rollMax = [1,1,2,2,2,3]
// Output: 34
// Explanation: There will be 2 rolls of die, if there are no constraints on the die, there are 6 * 6 = 36 possible combinations. In this case, looking at rollMax array, the numbers 1 and 2 appear at most once consecutively, therefore sequences (1,1) and (2,2) cannot occur, so the final answer is 36-2 = 34.
// Example 2:

// Input: n = 2, rollMax = [1,1,1,1,1,1]
// Output: 30
// Example 3:

// Input: n = 3, rollMax = [1,1,1,2,2,3]
// Output: 181
 

// Constraints:

// 1 <= n <= 5000
// rollMax.length == 6
// 1 <= rollMax[i] <= 15

int MOD=1000000007;
int dieSimulator_solve(int n,int prevRoll,int prevCount,int* rollMax,int rr,int dp[n][7][16]){
    if(n==0)
        return 1;
    if(dp[n-1][prevRoll][prevCount]>-1)
        return dp[n-1][prevRoll][prevCount];
    int ans=0;
    for(int i=1;i<=6;i++)
        if(i!=prevRoll || rollMax[i-1]>prevCount)
            ans=(ans+dieSimulator_solve(n-1,i,(i==prevRoll)?prevCount+1:1,rollMax,rr,dp))%MOD;
    return dp[n-1][prevRoll][prevCount]=ans;
}
int dieSimulator(int n,int* rollMax,int rr){
    int dp[n][7][16];
    memset(dp,-1,sizeof(dp));
    return dieSimulator_solve(n,0,0,rollMax,rr,dp);
}
