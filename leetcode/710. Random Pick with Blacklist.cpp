// Given a blacklist B containing unique integers from [0, N), write a function to return a uniform random integer from [0, N) which is NOT in B.

// Optimize it such that it minimizes the call to system’s Math.random().

// Note:

// 1 <= N <= 1000000000
// 0 <= B.length < min(100000, N)
// [0, N) does NOT include N. See interval notation.
// Example 1:

// Input: 
// ["Solution","pick","pick","pick"]
// [[1,[]],[],[],[]]
// Output: [null,0,0,0]
// Example 2:

// Input: 
// ["Solution","pick","pick","pick"]
// [[2,[]],[],[],[]]
// Output: [null,1,1,1]
// Example 3:

// Input: 
// ["Solution","pick","pick","pick"]
// [[3,[1]],[],[],[]]
// Output: [null,0,0,2]
// Example 4:

// Input: 
// ["Solution","pick","pick","pick"]
// [[4,[2]],[],[],[]]
// Output: [null,1,3,1]
// Explanation of Input Syntax:

// The input is two lists: the subroutines called and their arguments. Solution's constructor has two arguments, N and the blacklist B. pick has no arguments. Arguments are always wrapped with a list, even if there aren't any.

class Solution {
public:
    Solution(int N, vector<int>& black) {
        blacklist=black;
        blacklist.emplace_back(N);
        sort(blacklist.begin(),blacklist.end());
        n=blacklist.size();
        int count=0;
        for(int i=0;i<n;++i)
            blacklist[i]-=i;
    }
    
    int pick() {
        int r=rand()%blacklist[n-1];
        int next=upper_bound(blacklist.begin(),blacklist.end(),r)-blacklist.begin();
        return r+next;
    }
    
private:
    vector<int> blacklist;
    int n;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
