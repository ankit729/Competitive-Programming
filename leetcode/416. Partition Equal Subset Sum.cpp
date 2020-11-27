// Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.
 

// Constraints:

// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)
            return false;
        bitset<20001> possible; //20001=maxPossibleSum
        possible[0]=1;
        for(int x:nums)
            possible|=(possible<<x);
        return possible[sum>>1];
    }
};
