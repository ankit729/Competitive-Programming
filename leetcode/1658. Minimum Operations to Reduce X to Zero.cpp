// You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

// Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.

 

// Example 1:

// Input: nums = [1,1,4,2,3], x = 5
// Output: 2
// Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
// Example 2:

// Input: nums = [5,6,7,8,9], x = 4
// Output: -1
// Example 3:

// Input: nums = [3,2,20,1,1,3], x = 10
// Output: 5
// Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
 

// Constraints:

// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^4
// 1 <= x <= 10^9

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0)-x;
        if(sum<0)
            return -1;
        if(sum==0)
            return n;
        int curr=0,ans=0;
        int l=0;
        for(int r=0;r<n;r++){
            curr+=nums[r];
            while(curr>=sum){
                if(curr==sum)
                    ans=max(ans,r-l+1);
                curr-=nums[l++];
            }
        }
        return ans==0?-1:n-ans;
    }
};
