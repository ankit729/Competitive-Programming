// Given an integer array nums, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size(),count=0;
        vector<vector<int>> ans(1<<n);
        ans[count++]=vector<int>();
        for(int x:nums){
            int temp=count;
            for(int i=0;i<temp;++i){
                ans[count]=ans[i];
                ans[count++].emplace_back(x);
            }
        }
        return ans;
    }
};
