// You are given an integer array nums and an integer goal.

// You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. That is, if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).

// Return the minimum possible value of abs(sum - goal).

// Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.

 

// Example 1:

// Input: nums = [5,-7,3,5], goal = 6
// Output: 0
// Explanation: Choose the whole array as a subsequence, with a sum of 6.
// This is equal to the goal, so the absolute difference is 0.
// Example 2:

// Input: nums = [7,-9,15,-2], goal = -5
// Output: 1
// Explanation: Choose the subsequence [7,-9,-2], with a sum of -4.
// The absolute difference is abs(-4 - (-5)) = abs(1) = 1, which is the minimum.
// Example 3:

// Input: nums = [1,2,3], goal = -7
// Output: 7
 

// Constraints:

// 1 <= nums.length <= 40
// -10^7 <= nums[i] <= 10^7
// -10^9 <= goal <= 10^9

class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        if(goal==0)
            return 0;
        int n=nums.size(),ans=abs(goal);
        int pos=0,neg=0;
        for(auto& x:nums)
            (x<0)?neg+=x:pos+=x;
        if(goal<neg || pos<goal)
            return min({ans,abs(neg-goal),abs(goal-pos)});
        set<int> left{0};
        for(int i=0;i<n;i+=2){
            for(auto& x:vector<int>(left.begin(),left.end())){
                if(left.insert(x+nums[i]).second){
                    ans=min(ans,abs(goal-x-nums[i]));
                    if(ans==0)
                        return 0;
                }
            }
        }
        unordered_set<int> right{0};
        for(int i=1;i<n;i+=2){
            for(auto& x:vector<int>(right.begin(),right.end())){
                if(right.insert(x+nums[i]).second){
                    auto it=left.lower_bound(goal-x-nums[i]);
                    if(it!=left.end())
                        ans=min(ans,abs(goal-x-nums[i]-*it));
                    if(it!=left.begin())
                        ans=min(ans,abs(goal-x-nums[i]-*prev(it)));
                    if(ans==0)
                        return ans;
                }
            }
        }
        return ans;
    }
};
