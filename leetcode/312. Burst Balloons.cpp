// Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

// Find the maximum coins you can collect by bursting the balloons wisely.

// Note:

// You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
// 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
// Example:

// Input: [3,1,5,8]
// Output: 167 
// Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//              coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

class Solution {
public:
    int maxCoins(vector<int> nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int dp[n+2][n+2];
        memset(dp,0,sizeof(dp));
        for(int len=1;len<=n;++len)
            for(int l=1,r=len;r<=n;++l,++r)
                for(int i=l;i<=r;++i)
                    dp[l][r]=max(dp[l][r],dp[l][i-1]+nums[l-1]*nums[i]*nums[r+1]+dp[i+1][r]);
        return dp[1][n];
    }
};
