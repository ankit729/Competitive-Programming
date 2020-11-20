// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

// You are given a target value to search. If found in the array return true, otherwise return false.

// Example 1:

// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
// Example 2:

// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
// Follow up:

// This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
// Would this affect the run-time complexity? How and why?

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0)
            return false;
        int l=0,r=n-1;
        while(l<=r){
            while(l+1<=r && nums[l]==nums[l+1])
                l++;
            while(r-1>=l && nums[r]==nums[r-1])
                r--;
            int mid=(l+r)>>1;
            if(nums[mid]==target || nums[l]==target || nums[r]==target)
                return true;
            else if(nums[mid]<=nums[r]){
                if(nums[mid]<target && target<nums[r])
                    l=mid+1,r--;
                else
                    l++,r=mid-1;
            }
            else if(nums[mid]>=nums[l]){
                if(nums[l]<target && target<nums[mid])
                    l++,r=mid-1;
                else
                    l=mid+1,r--;
            }
        }
        return false;
    }
};
