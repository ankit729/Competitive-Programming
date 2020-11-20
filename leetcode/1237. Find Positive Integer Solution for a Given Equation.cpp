/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& g, int z) {
        vector<vector<int>> ans;
        for(int x=1,y;x<=z;x++)
            if((y=findSolutionHelper(g,x,z))>0)
                ans.push_back({x,y});
        return ans;
    }
private:
    int findSolutionHelper(CustomFunction& g, int x, int z) {
        int l=1,r=1000;
        while(l<=r){
            int mid=(l+r)>>1;
            int val=g.f(x,mid);
            if(val==z)
                return mid;
            if(val<z)
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
};
