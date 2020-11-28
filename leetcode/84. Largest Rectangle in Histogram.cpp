// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 


// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 


// The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

// Example:

// Input: [2,1,5,6,2,3]
// Output: 10

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty())
            return 0;
        int n=heights.size();
        int ans=0;
        stack<int> stack;
        int i=0;
        while(i<n){
            if(stack.empty() || heights[i]>=heights[stack.top()]){
                stack.push(i++);
                continue;
            }
            while(!stack.empty() && heights[i]<heights[stack.top()]){
                int curr=heights[stack.top()];
                stack.pop();
                ans=max(ans,curr*(stack.empty()?i:i-stack.top()-1));
            }
            stack.push(i++);
        }
        while(!stack.empty()){
            int curr=heights[stack.top()];
            stack.pop();
            ans=max(ans,curr*(stack.empty()?i:i-stack.top()-1));
        }
        return ans;
    }
};
