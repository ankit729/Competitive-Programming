// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
//              because they are adjacent houses.
// Example 2:

// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.

int max(int a,int b){
    return (a>b)?a:b;
}
int rob(int* nums,int r){
    if(r<=3){
        int ans=0;
        for(int i=0;i<r;i++)
            ans=max(ans,nums[i]);
        return ans;
    }
    int ans;
    int dp[r];
    dp[0]=nums[0];
    dp[1]=nums[1];
    dp[2]=nums[0]+nums[2];
    for(int i=3;i<r-1;i++)
        dp[i]=nums[i]+max(dp[i-2],dp[i-3]);
    ans=max(dp[r-2],dp[r-3]);
    dp[1]=nums[1];
    dp[2]=nums[2];
    dp[3]=nums[1]+nums[3];
    for(int i=4;i<r;i++)
        dp[i]=nums[i]+max(dp[i-2],dp[i-3]);
    ans=max(ans,max(dp[r-1],dp[r-2]));
    return ans;
}
