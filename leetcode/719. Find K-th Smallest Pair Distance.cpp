// Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

// Example 1:
// Input:
// nums = [1,3,1]
// k = 1
// Output: 0 
// Explanation:
// Here are all the pairs:
// (1,3) -> 2
// (1,1) -> 0
// (3,1) -> 2
// Then the 1st smallest distance pair is (1,1), and its distance is 0.
// Note:
// 2 <= len(nums) <= 10000.
// 0 <= nums[i] < 1000000.
// 1 <= k <= len(nums) * (len(nums) - 1) / 2.

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int l=0,r=nums.back()-nums[0];l<=r;){
            int mid=l+((r-l)>>1);
            int temp=get(nums,mid);
            if(temp<k)
                l=mid+1;
            else
                ans=mid,r=mid-1;
        }
        return ans;
    }
private:
    int get(vector<int>& nums, int target) {
        int n=nums.size(),ans=0;
        for(int l=0,r=0;l<n;++l){
            while(r<n && nums[l]+target>=nums[r])
                r++;
            ans+=r-1-l;
        }
        return ans;
    }
};
