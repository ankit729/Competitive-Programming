// Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

// We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

 

// Example 1:

// Input: nums = [4,2,3]
// Output: true
// Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
// Example 2:

// Input: nums = [4,2,1]
// Output: false
// Explanation: You can't get a non-decreasing array by modify at most one element.
 

// Constraints:

// n == nums.length
// 1 <= n <= 10^4
// -10^5 <= nums[i] <= 10^5

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l+1<n && nums[l]<=nums[l+1])
            l++;
        while(r>l && nums[r-1]<=nums[r])
            r--;
        if(r-1-l>1)
            return false;
        if(r-l-1==1)
            return nums[l]<=nums[r];
        return (l==0 || nums[l-1]<=nums[r] || r==n-1 || nums[l]<=nums[r+1]);
    }
};
