// There is a room with n lights which are turned on initially and 4 buttons on the wall. After performing exactly m unknown operations towards buttons, you need to return how many different kinds of status of the n lights could be.

// Suppose n lights are labeled as number [1, 2, 3 ..., n], function of these 4 buttons are given below:

// Flip all the lights.
// Flip lights with even numbers.
// Flip lights with odd numbers.
// Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...
 

// Example 1:

// Input: n = 1, m = 1.
// Output: 2
// Explanation: Status can be: [on], [off]
 

// Example 2:

// Input: n = 2, m = 1.
// Output: 3
// Explanation: Status can be: [on, off], [off, on], [off, off]
 

// Example 3:

// Input: n = 3, m = 1.
// Output: 4
// Explanation: Status can be: [off, on, off], [on, off, on], [off, off, off], [off, on, on].
 

// Note: n and m both fit in range [0, 1000].

class Solution {
public:
    int flipLights(int n, int m) {
        n=min(n,6);
        int shift=6-n;
        unordered_set<int> st;
        for(int i=0;i<16;++i){
            int setbits=__builtin_popcount(i);
            if((setbits&1)==(m&1) && setbits<=m){
                int lights=0;
                if((i>>0)&1)
                    lights^=0b111111>>shift;
                if((i>>1)&1)
                    lights^=0b010101>>shift;
                if((i>>2)&1)
                    lights^=0b101010>>shift;
                if((i>>3)&1)
                    lights^=0b100100>>shift;
                st.insert(lights);
            }
        }
        return st.size();
    }
};
