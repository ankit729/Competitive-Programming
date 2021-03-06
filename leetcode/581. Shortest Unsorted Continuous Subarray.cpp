// Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

// Return the shortest such subarray and output its length.

 

// Example 1:

// Input: nums = [2,6,4,8,10,9,15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
// Example 2:

// Input: nums = [1,2,3,4]
// Output: 0
// Example 3:

// Input: nums = [1]
// Output: 0
 

// Constraints:

// 1 <= nums.length <= 10^4
// -10^5 <= nums[i] <= 10^5

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=1,j=n-2;
        while(i<n && nums[i]>=nums[i-1])
            i++;
        if(i==n)
            return 0;
        while(j>=0 && nums[j]<=nums[j+1])
            j--;
        int left=*min_element(nums.begin()+i,nums.end());
        int right=*max_element(nums.begin(),nums.begin()+j+1);
        int l=upper_bound(nums.begin(),nums.begin()+i,left)-nums.begin();
        int r=lower_bound(nums.begin()+j+1,nums.end(),right)-nums.begin()-1;
        return l>=r?0:r-l+1;
    }
};
