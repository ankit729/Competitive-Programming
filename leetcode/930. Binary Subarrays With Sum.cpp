// In an array A of 0s and 1s, how many non-empty subarrays have sum S?

 

// Example 1:

// Input: A = [1,0,1,0,1], S = 2
// Output: 4
// Explanation: 
// The 4 subarrays are bolded below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
 

// Note:

// A.length <= 30000
// 0 <= S <= A.length
// A[i] is either 0 or 1.

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n=A.size(),ans=0;
        for(int l=0,sl=0,r=0,sr=0,i=0;i<n;++i){
            sl+=A[i];
            while(l<i && sl>S)
                sl-=A[l++];
            sr+=A[i];
            while(r<i && (sr>S || (sr==S && A[r]==0)))
                sr-=A[r++];
            if(sl==S)
                ans+=r-l+1;
        }
        return ans;
    }
};
