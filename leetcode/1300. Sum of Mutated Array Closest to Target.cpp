// Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.

// In case of a tie, return the minimum such integer.

// Notice that the answer is not neccesarilly a number from arr.

 

// Example 1:

// Input: arr = [4,9,3], target = 10
// Output: 3
// Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.
// Example 2:

// Input: arr = [2,3,5], target = 10
// Output: 5
// Example 3:

// Input: arr = [60864,25176,27249,21296,20204], target = 56803
// Output: 11361
 

// Constraints:

// 1 <= arr.length <= 10^4
// 1 <= arr[i], target <= 10^5

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int sum[n+1];
        sum[0]=0;
        for(int i=1;i<=n;++i)
            sum[i]=sum[i-1]+arr[i-1];
        int ans=arr[n-1];
        int l=0,r=arr[n-1],m=sum[n-1]+arr[n-1]-target;
        while(l<=r){
            int mid=l+((r-l)>>1);
            int index=upper_bound(arr.begin(),arr.end(),mid)-arr.begin();
            int temp=sum[index]+(n-index)*mid-target;
            if(abs(temp)<abs(m))
                ans=mid,m=temp;
            else if(abs(temp)==abs(m))
                ans=min(ans,mid);
            if(temp<0)
                l=mid+1;
            else
                r=mid-1;
        }
        return ans;
    }
};
