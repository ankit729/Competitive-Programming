// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

// Example:

// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6

class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        for(int l=0,lMax=0,r=height.size()-1,rMax=0;l<r;){
            lMax=max(lMax,height[l]);
            rMax=max(rMax,height[r]);
            ans+=(lMax<rMax)?lMax-height[l++]:rMax-height[r--];
        }
        return ans;
    }
};
