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
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        if(n<=3)
            return ans;
        if(accumulate(nums.end()-4,nums.end(),0)<target)
            return ans;
        vector<int> start,end;
        for(int i=0;i<n;++i){
            start.push_back(i);
            while(i+1<n && nums[i]==nums[i+1])
                i++;
            end.push_back(i);
        }
        int size=start.size();
        for(int ii=0;ii<size;++ii){
            int i=start[ii];
            if(nums[i]>target/4)
                break;
            for(int j=i+1,ji=(j<n && nums[i]==nums[j])?ii:ii+1;ji<size;++ji,j=(ji<size)?start[ji]:n){
                if(nums[i]+nums[j]>target/2)
                    break;
                int k=j+1,l=n-1;
                int ki=(k<n && nums[j]==nums[k])?ji:ji+1;
                int li=size-1;
                while(k<l){
                    int sum=nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k=end[ki++]+1;
                        l=start[li--]-1;
                    }
                    else if(sum<target)
                        k=end[ki++]+1;
                    else
                        l=start[li--]-1;
                }
            }
        }
        return ans;
    }
};
