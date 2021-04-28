// Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

// Write an algorithm to minimize the largest sum among these m subarrays.

 

// Example 1:

// Input: nums = [7,2,5,10,8], m = 2
// Output: 18
// Explanation:
// There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8],
// where the largest sum among the two subarrays is only 18.
// Example 2:

// Input: nums = [1,2,3,4,5], m = 2
// Output: 9
// Example 3:

// Input: nums = [1,4,4], m = 3
// Output: 4
 

// Constraints:

// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 10^6
// 1 <= m <= min(50, nums.length)

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        int ans=r;
        while(l<=r){
            int mid=l+((r-l)>>1);
            int temp=helper(nums,mid);
            if(temp<=m)
                ans=min(ans,mid),r=mid-1;
            else
                l=mid+1;
        }
        return ans;
    }
private:
    int helper(vector<int>& nums, int x) {
        int ans=1;
        int sum=x;
        for(auto& num:nums){
            if(sum<num)
                ans++,sum=x;
            sum-=num;
        }
        return ans;
    }
};
