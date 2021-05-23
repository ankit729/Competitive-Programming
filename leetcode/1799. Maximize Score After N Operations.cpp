// You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

// In the ith operation (1-indexed), you will:

// Choose two elements, x and y.
// Receive a score of i * gcd(x, y).
// Remove x and y from nums.
// Return the maximum score you can receive after performing n operations.

// The function gcd(x, y) is the greatest common divisor of x and y.

 

// Example 1:

// Input: nums = [1,2]
// Output: 1
// Explanation: The optimal choice of operations is:
// (1 * gcd(1, 2)) = 1
// Example 2:

// Input: nums = [3,4,6,8]
// Output: 11
// Explanation: The optimal choice of operations is:
// (1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
// Example 3:

// Input: nums = [1,2,3,4,5,6]
// Output: 14
// Explanation: The optimal choice of operations is:
// (1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
 

// Constraints:

// 1 <= n <= 7
// nums.length == 2 * n
// 1 <= nums[i] <= 10^6

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(1<<n);
        vector<bool> visited(n);
        return helper(nums,1,0,dp,visited);
    }
private:
    int helper(vector<int>& nums, int i, int mask, vector<int>& dp, vector<bool>& visited) {
        if(i>(nums.size()>>1))
            return 0;
        if(dp[mask]!=0)
            return dp[mask];
        for(int j=0;j<nums.size();++j){
            if(visited[j])
                continue;
            visited[j]=true;
            for(int k=j+1;k<nums.size();++k){
                if(visited[k])
                    continue;
                visited[k]=true;
                dp[mask]=max(dp[mask],i*gcd(nums[j],nums[k])+helper(nums,i+1,mask|(1<<j)|(1<<k),dp,visited));
                visited[k]=false;
            }
            visited[j]=false;
        }
        return dp[mask];
    }
};
