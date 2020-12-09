// Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

// Example: 

// Input: s = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: the subarray [4,3] has the minimal length under the problem constraint.
// Follow up:
// If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX,l=0,r=0;
        while(r<n){
            s-=nums[r++];
            if(s<=0){
                do{
                    s+=nums[l++];
                }while(s<=0);
                ans=min(ans,r-l+1);
            }
        }
        return (ans==INT_MAX)?0:ans;
    }
};
