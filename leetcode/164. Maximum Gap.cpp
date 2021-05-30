// Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

// You must write an algorithm that runs in linear time and uses linear extra space.

 

// Example 1:

// Input: nums = [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
// Example 2:

// Input: nums = [10]
// Output: 0
// Explanation: The array contains less than 2 elements, therefore return 0.
 

// Constraints:

// 1 <= nums.length <= 10^4
// 0 <= nums[i] <= 10^9

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size(),ans=INT_MIN;
        if(n<=1)
            return 0;
        int m=INT_MAX,M=INT_MIN;
        for(auto& x:nums)
            m=min(m,x),M=max(M,x);
        int gap=ceil((double) (M-m)/(n-1));
        int bmin[n-1],bmax[n-1];
        fill(bmin,bmin+(n-1),INT_MAX);
        fill(bmax,bmax+(n-1),INT_MIN);
        for(auto& x:nums){
            if(x==m || x==M)
                continue;
            int i=(x-m)/gap;
            bmin[i]=min(x,bmin[i]);
            bmax[i]=max(x,bmax[i]);
        }
        int prev=m;
        for(int i=0;i<n-1;++i){
            if(bmin[i]==INT_MAX)
                continue;
            ans=max(ans,bmin[i]-prev);
            prev=bmax[i];
        }
        return max(ans,M-prev);
    }
};
