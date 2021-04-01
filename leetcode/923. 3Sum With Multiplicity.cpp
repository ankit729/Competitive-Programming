// Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.

// As the answer can be very large, return it modulo 10^9 + 7.

 

// Example 1:

// Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
// Output: 20
// Explanation: 
// Enumerating by the values (arr[i], arr[j], arr[k]):
// (1, 2, 5) occurs 8 times;
// (1, 3, 4) occurs 8 times;
// (2, 2, 4) occurs 2 times;
// (2, 3, 3) occurs 2 times.
// Example 2:

// Input: arr = [1,1,2,2,2,2], target = 5
// Output: 12
// Explanation: 
// arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
// We choose one 1 from [1,1] in 2 ways,
// and two 2s from [2,2,2,2] in 6 ways.
 

// Constraints:

// 3 <= arr.length <= 3000
// 0 <= arr[i] <= 100
// 0 <= target <= 300

class Solution {
    #define ll long long int
    ll MOD=1e9+7;
public:
    int threeSumMulti(vector<int>& nums, int target) {
        int n=nums.size();
        ll ans=0;
        sort(nums.begin(),nums.end());
        if(n<=2 || accumulate(nums.end()-3,nums.end(),0)<target)
            return ans;
        vector<int> start,end;
        for(int i=0;i<n;++i){
            start.push_back(i);
            while(i+1<n && nums[i]==nums[i+1])
                i++;
            end.push_back(i);
        }
        int size=start.size();
        auto helper=[&start,&end](int a, int b, int c)->ll {
            if(a!=b){
                if(b!=c)
                    return 1LL*(end[a]-start[a]+1)*(end[b]-start[b]+1)*(end[c]-start[c]+1);
                return 1LL*(end[a]-start[a]+1)*(end[b]-start[b]+1)*(end[b]-start[b])/2;
            }
            if(b!=c)
                return 1LL*(end[a]-start[a]+1)*(end[a]-start[a])/2*(end[c]-start[c]+1);
            return 1LL*(end[a]-start[a]+1)*(end[a]-start[a])*(end[a]-start[a]-1)/6;
        };
        for(int index=0;index<size && nums[start[index]]<=target/3;++index){
            int i=start[index];
            int j=i+1,k=n-1;
            int ji=(j<n && nums[i]==nums[j])?index:index+1;
            int ki=size-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==target){
                    ans+=helper(index,ji,ki)%MOD;
                    ans%=MOD;
                    j=end[ji++]+1;
                    k=start[ki--]-1;
                }
                else if(sum<target)
                    j=end[ji++]+1;
                else
                    k=start[ki--]-1;
            }
        }
        return ans;
    }
};
