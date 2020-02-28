// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

// Example:

// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6

int max(int a,int b){
    return (a>b)?a:b;
}
int trap(int* height,int hr){
    int left=0,left_max=0,right=hr-1,right_max=0;
    int ans=0;
    while(left<=right){
        left_max=max(left_max,height[left]);
        right_max=max(right_max,height[right]);
        if(left_max<right_max)
            ans+=left_max-height[left++];
        else
            ans+=right_max-height[right--];
    }
    return ans;
}
