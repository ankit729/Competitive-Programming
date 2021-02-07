// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]
 

// Constraints:

// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> combo;
        helper(candidates,n,0,ans,combo,target);
        return ans;
    }
private:
    void helper(vector<int>& nums, int& n, int i, vector<vector<int>>& ans, vector<int>& combo, int target) {
        if(target==0){
            ans.push_back(combo);
            return;
        }
        if(i==n || target<0)
            return;
        combo.push_back(nums[i]);
        helper(nums,n,i+1,ans,combo,target-nums[i]);
        combo.pop_back();
        while(i+1<n && nums[i]==nums[i+1])
            i++;
        helper(nums,n,i+1,ans,combo,target);
    }
};
