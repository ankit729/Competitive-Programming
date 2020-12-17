// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Example 2:

// Input: nums = []
// Output: []
// Example 3:

// Input: nums = [0]
// Output: []
 

// Constraints:

// 0 <= nums.length <= 3000
// -10^5 <= nums[i] <= 10^5

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        if(n<=2)
            return ans;
        vector<int> start,end;
        for(int i=0;i<n;++i){
            start.push_back(i);
            while(i+1<n && nums[i]==nums[i+1])
                i++;
            end.push_back(i);
        }
        int size=start.size();
        for(int index=0;index<size;++index){
            int i=start[index];
            if(nums[i]>0)
                break;
            int j=i+1,k=n-1;
            int ji=(j<n && nums[i]==nums[j])?index:index+1;
            int ki=size-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j=end[ji++]+1;
                    k=start[ki--]-1;
                }
                else if(sum<0)
                    j=end[ji++]+1;
                else
                    k=start[ki--]-1;
            }
        }
        return ans;
    }
};
