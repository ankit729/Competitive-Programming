// Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

 

// Example 1:

// Input: nums = [1,2,3,1], k = 3, t = 0
// Output: true
// Example 2:

// Input: nums = [1,0,1,1], k = 1, t = 2
// Output: true
// Example 3:

// Input: nums = [1,5,9,1,5,9], k = 2, t = 3
// Output: false
 

// Constraints:

// 0 <= nums.length <= 2 * 10^4
// -2^31 <= nums[i] <= 2^31 - 1
// 0 <= k <= 10^4
// 0 <= t <= 2^31 - 1

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& arr, int k, int t) {
        if(k==0)
            return false;
        int n=arr.size();
        vector<pair<int,int>> nums;
        nums.reserve(n);
        for(int i=0;i<n;++i)
            nums.push_back({arr[i],i});
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if((long) nums[j].first-nums[i].first<=t){
                    if(abs(nums[i].second-nums[j].second)<=k)
                        return true;
                }
                else
                    break;
            }
        }
        return false;
    }
};
