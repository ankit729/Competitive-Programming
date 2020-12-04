// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// You may return the answer in any order.

 

// Example 1:

// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
// Example 2:

// Input: n = 1, k = 1
// Output: [[1]]
 

// Constraints:

// 1 <= n <= 20
// 1 <= k <= n

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> C;
        dfs(ans,n,C,1,k);
        return ans;
    }
private:
    void dfs(vector<vector<int>>& ans, int& n, vector<int>& C, int index, int k) {
        if(k==0){
            ans.push_back(C);
            return;
        }
        for(int i=index;i<=n-k+1;++i){
            C.push_back(i);
            dfs(ans,n,C,i+1,k-1);
            C.pop_back();
        }
    }
};
