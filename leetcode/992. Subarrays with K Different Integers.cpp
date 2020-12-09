// Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly K.

// (For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

// Return the number of good subarrays of A.

 

// Example 1:

// Input: A = [1,2,1,2,3], K = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
// Example 2:

// Input: A = [1,2,1,3,4], K = 3
// Output: 3
// Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

// Note:

// 1 <= A.length <= 20000
// 1 <= A[i] <= A.length
// 1 <= K <= A.length

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n=A.size();
        vector<int> nums(n+1,0);    //1<=A[i]<=n else unordered_map<int,int> nums;
        int count=1,l=0,r=0,ans=0;
        for(auto& x:A){
            if(nums[x]++==0)
                K--;
            if(K<0){
                --nums[A[l++]];
                K++;
                count=1;
            }
            if(K==0){
                while(nums[A[l]]>1){
                    --nums[A[l++]];
                    count++;
                }
                ans+=count;
            }
        }
        return ans;
    }
};
