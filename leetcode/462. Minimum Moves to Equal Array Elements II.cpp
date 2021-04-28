// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

// In one move, you can increment or decrement an element of the array by 1.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: 2
// Explanation:
// Only two moves are needed (remember each move increments or decrements one element):
// [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
// Example 2:

// Input: nums = [1,10,2,9]
// Output: 16
 

// Constraints:

// n == nums.length
// 1 <= nums.length <= 10^5
// -10^9 <= nums[i] <= 10^9

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long int change[n];
        for(long int i=0,sum=0;i<n;++i){
            change[i]=nums[i]*i-sum;
            sum+=nums[i];
        }
        for(long int i=n-1,sum=0;i>=0;--i){
            change[i]+=sum-nums[i]*(n-i-1);
            sum+=nums[i];
        }
        return *min_element(change,change+n);
    }
};