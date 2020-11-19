// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

// Example 1:

// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int maxl=INT_MIN,maxr=INT_MIN,curr=1;
        for(int i=0;i<n;i++){
            curr*=nums[i];
            maxl=max(maxl,curr);
            if(curr==0)
                curr=1;
        }
        curr=1;
        for(int i=n-1;i>=0;i--){
            curr*=nums[i];
            maxr=max(maxr,curr);
            if(curr==0)
                curr=1;
        }
        return max(maxl,maxr);
    }
};
