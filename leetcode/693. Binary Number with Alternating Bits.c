// Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

// Example 1:
// Input: 5
// Output: True
// Explanation:
// The binary representation of 5 is: 101
// Example 2:
// Input: 7
// Output: False
// Explanation:
// The binary representation of 7 is: 111.
// Example 3:
// Input: 11
// Output: False
// Explanation:
// The binary representation of 11 is: 1011.
// Example 4:
// Input: 10
// Output: True
// Explanation:
// The binary representation of 10 is: 1010.

bool hasAlternatingBits(int n){
    int a=1+log10(n)/log10(2);
    bool p=1&n;
    for(int i=1;i<a;i++){
        n>>=1;
        bool q=1&n;
        if(p==q)
            return false;
        p=q;
    }
    return true;
}
