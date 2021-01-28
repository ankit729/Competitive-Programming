// Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
// Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

// Note:
// A naive algorithm of O(n2) is trivial. You MUST do better than that.

// Example:

// Input: nums = [-2,5,-1], lower = -2, upper = 2,
// Output: 3 
// Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective sums are: -2, -1, 2.
 

// Constraints:

// 0 <= nums.length <= 10^4

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        vector<long int> v(n+1);
        for(int i=1;i<=n;++i)
            v[i]=v[i-1]+nums[i-1];
        return mergeSort(v,0,n+1,lower,upper);
    }
private:
    int mergeSort(vector<long int>& v, int l, int r, int lower, int upper) {
        if(r-l<=1)
            return 0;
        int mid=l+((r-l)>>1);
        int ans=mergeSort(v,l,mid,lower,upper)+mergeSort(v,mid,r,lower,upper);
        for(int i=l,j=mid,k=mid;i<mid;++i){
            while(j<r && v[j]-v[i]<lower)
                j++;
            while(k<r && v[k]-v[i]<=upper)
                k++;
            ans+=k-j;
        }
        inplace_merge(v.begin()+l,v.begin()+mid,v.begin()+r);
        return ans;
    }
};
