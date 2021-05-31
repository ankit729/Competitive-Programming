// Given an integer array nums, return the sum of floor(nums[i] / nums[j]) for all pairs of indices 0 <= i, j < nums.length in the array. Since the answer may be too large, return it modulo 10^9 + 7.

// The floor() function returns the integer part of the division.

 

// Example 1:

// Input: nums = [2,5,9]
// Output: 10
// Explanation:
// floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
// floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
// floor(5 / 2) = 2
// floor(9 / 2) = 4
// floor(9 / 5) = 1
// We calculate the floor of the division for every pair of indices in the array then sum them up.
// Example 2:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 49
 

// Constraints:

// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^5

const int MOD=1e9+7;
class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int n=nums.size(),ans=0;
        int M=*max_element(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        int freq[M+1],sieve[M+1];
        memset(freq,0,sizeof(freq));
        memset(sieve,0,sizeof(sieve));
        for(auto& x:nums)
            freq[x]++;
        for(int i=0;i<n;){
            for(int j=nums[i];j<=M;j+=nums[i])
                sieve[j]=(sieve[j]+freq[nums[i]])%MOD;
            i+=freq[nums[i]];
        }
        for(int i=1;i<=M;++i)
            sieve[i]=(sieve[i]+sieve[i-1])%MOD;
        for(auto& x:nums)
            ans=(ans+sieve[x])%MOD;
        return ans;
    }
};
