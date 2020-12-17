// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

// Notice that the solution set must not contain duplicate quadruplets.

 

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [], target = 0
// Output: []
 

// Constraints:

// 0 <= nums.length <= 200
// -10^9 <= nums[i] <= 10^9
// -10^9 <= target <= 10^9

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size(),k=4;
        sort(nums.begin(),nums.end());
        if(n<k)
            return {};
        vector<int> start,end;
        for(int i=0;i<n;++i){
            start.push_back(i);
            while(i+1<n && nums[i]==nums[i+1])
                i++;
            end.push_back(i);
        }
        return kSum(nums,n,start,end,start.size(),0,0,target,k);
    }
private:
    vector<vector<int>> kSum(vector<int>& nums, int n, vector<int>& start, vector<int>& end, int size, int i, int ii, int target, int k) {
        if(i>n-k || accumulate(nums.begin()+i,nums.begin()+i+k,0)>target || accumulate(nums.end()-k,nums.end(),0)<target)
            return {};
        if(k==2)
            return twoSum(nums,n,start,end,size,i,ii,target);
        vector<vector<int>> ans;
        for(int j=i,ji=ii;ji<size;++ji,j=(ji<size)?start[ji]:n){
            vector<vector<int>> temp=kSum(nums,n,start,end,size,j+1,(j+1<n && nums[j]==nums[j+1])?ji:ji+1,target-nums[j],k-1);
            for(auto& x:temp){
                ans.push_back({nums[j]});
                ans.back().insert(ans.back().end(),x.begin(),x.end());
            }
        }
        return ans;
    }
    vector<vector<int>> twoSum(vector<int>& nums, int n, vector<int>& start, vector<int>& end, int size, int i, int ii, int target) {
        vector<vector<int>> ans;
        int l=i,r=n-1;
        int li=ii,ri=size-1;
        while(l<r){
            int sum=nums[l]+nums[r];
            if(sum==target){
                ans.push_back({nums[l],nums[r]});
                l=end[li++]+1;
                r=start[ri--]-1;
            }
            else if(sum<target)
                l=end[li++]+1;
            else
                r=start[ri--]-1;
        }
        return ans;
    }
};
