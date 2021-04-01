// You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

// One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

// Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

// Note: You cannot rotate an envelope.

 

// Example 1:

// Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
// Output: 3
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
// Example 2:

// Input: envelopes = [[1,1],[1,1],[1,1]]
// Output: 1
 

// Constraints:

// 1 <= envelopes.length <= 5000
// envelopes[i].length == 2
// 1 <= wi, hi <= 10^4

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](auto& a, auto& b) {
            if(a[0]!=b[0])
                return a[0]<b[0];
            return a[1]>b[1];
        });
        vector<int> dp;
        for(auto& x:envelopes){
            if(dp.empty() || x[1]>dp.back())
                dp.push_back(x[1]);
            else
                *lower_bound(dp.begin(),dp.end(),x[1])=x[1];
        }
        return dp.size();
    }
};
