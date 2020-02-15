// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
//              Total amount you can rob = 2 + 9 + 1 = 12.

int max(int a,int b){
    return (a>b)?a:b;
}
int rob(int* nums,int r){
    if(r<=2){
        int ans=0;
        for(int i=0;i<r;i++)
            ans=max(ans,nums[i]);
        return ans;
    }
    if(r==3)
        return max(nums[0]+nums[2],nums[1]);
    int ans;
    int dp[r];
    dp[0]=nums[0];
    dp[1]=nums[1];
    dp[2]=nums[0]+nums[2];
    for(int i=3;i<r;i++)
        dp[i]=nums[i]+max(dp[i-2],dp[i-3]);
    ans=max(dp[r-1],dp[r-2]);
    return ans;
}
