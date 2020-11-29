// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size(),count=0;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans(1<<n);
        ans[count++]=vector<int>();
        for(int i=0,l=0,r=count;i<n;++i){
            l=(i==0 || nums[i]!=nums[i-1])?0:r;
            r=count;
            for(int j=l;j<r;++j){
                ans[count]=ans[j];
                ans[count++].emplace_back(nums[i]);
            }
        }
        ans.resize(count);
        return ans;
    }
};
