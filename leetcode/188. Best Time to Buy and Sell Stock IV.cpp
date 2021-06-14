// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
// Example 2:

// Input: k = 2, prices = [3,2,6,5,0,3]
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

// Constraints:

// 0 <= k <= 100
// 0 <= prices.length <= 1000
// 0 <= prices[i] <= 1000

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k==0)
            return 0;
        int n=prices.size();
        int buy[k],sell[k];
        fill(buy,buy+k,INT_MAX);
        fill(sell,sell+k,0);
        for(auto& x:prices){
            buy[0]=min(buy[0],x);
            sell[0]=max(sell[0],x-buy[0]);
            for(int i=1;i<k;++i){
                buy[i]=min(buy[i],x-sell[i-1]);
                sell[i]=max(sell[i],x-buy[i]);
            }
        }
        return sell[k-1];
    }
};
