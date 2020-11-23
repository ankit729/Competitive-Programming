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

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<=3)
            return *max_element(nums.begin(),nums.end());
        return max(robHelper(nums,0,n-2),robHelper(nums,1,n-1));
    }
private:
    int robHelper(vector<int>& nums, int l, int r) {
        int dp[r-l+1];
        dp[0]=nums[l];
        dp[1]=nums[l+1];
        dp[2]=nums[l]+nums[l+2];
        for(int i=l+3;i<=r;i++)
            dp[i-l]=nums[i]+max(dp[i-l-2],dp[i-l-3]);
        return max(dp[r-l-1],dp[r-l]);
    }
};
