// Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has piles[i] bananas.  The guards have gone and will come back in H hours.

// Koko can decide her bananas-per-hour eating speed of K.  Each hour, she chooses some pile of bananas, and eats K bananas from that pile.  If the pile has less than K bananas, she eats all of them instead, and won't eat any more bananas during this hour.

// Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.

// Return the minimum integer K such that she can eat all the bananas within H hours.

 

// Example 1:

// Input: piles = [3,6,7,11], H = 8
// Output: 4
// Example 2:

// Input: piles = [30,11,23,4,20], H = 5
// Output: 30
// Example 3:

// Input: piles = [30,11,23,4,20], H = 6
// Output: 23
 

// Constraints:

// 1 <= piles.length <= 10^4
// piles.length <= H <= 10^9
// 1 <= piles[i] <= 10^9

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        long int sum=accumulate(piles.begin(),piles.end(),0L);
        int l=(sum-1)/H+1;
        int r=*max_element(piles.begin(),piles.end());
        // int ans=INT_MAX;         //binary search slower
        // while(l<=r){
        //     int mid=l+((r-l)>>1);
        //     if(minEatingSpeedHelper(piles,mid)<=H){
        //         ans=min(ans,mid);
        //         r=mid-1;
        //     }
        //     else
        //         l=mid+1;
        // }
        // return ans;
        
        for(int i=l;i<=r;i++)       //linear search faster than binary search
            if(minEatingSpeedHelper(piles,i)<=H)
                return i;
        return -1;
    }
private:
    int minEatingSpeedHelper(vector<int>& piles, int speed) {
        int ans=0;
        for(int x:piles)
            ans+=(x-1)/speed+1;     //ceil((double) x/speed);
        return ans;
    }
};
