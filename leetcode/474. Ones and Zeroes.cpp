// You are given an array of binary strings strs and two integers m and n.

// Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

// A set x is a subset of a set y if all elements of x are also elements of y.

 

// Example 1:

// Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
// Output: 4
// Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
// Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
// {"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
// Example 2:

// Input: strs = ["10","0","1"], m = 1, n = 1
// Output: 2
// Explanation: The largest subset is {"0", "1"}, so the answer is 2.
 

// Constraints:

// 1 <= strs.length <= 600
// 1 <= strs[i].length <= 100
// strs[i] consists only of digits '0' and '1'.
// 1 <= m, n <= 100

class Solution {
public:
    int findMaxForm(vector<string>& strs, int M, int N) {
        int n=strs.size(),ans=0;
        pair<int,int> c[n];
        for(int i=0;i<n;++i){
            int zeroes=count(strs[i].begin(),strs[i].end(),'0');
            c[i]={zeroes,strs[i].size()-zeroes};
        }
        sort(c,c+n);
        ans=max(ans,helper(c,n,M,N));
        sort(c,c+n,[](auto& a, auto& b){return a.second<b.second;});
        ans=max(ans,helper(c,n,M,N));
        sort(c,c+n,[&M,&N](auto& a, auto& b){
            if(a.first+a.second!=b.first+b.second)
                return a.first+a.second<b.first+b.second;
            if(M<=N)
                return a.first<b.first;
            return a.second<b.second;
        });
        ans=max(ans,helper(c,n,M,N));
        return ans;
    }
private:
    int helper(pair<int,int>* c, int n, int M, int N) {
        int ans=0;
        for(int i=0;i<n;++i){
            if(M>=c[i].first && N>=c[i].second){
                M-=c[i].first;
                N-=c[i].second;
                ans++;
            }
        }
        return ans;
    }
};
