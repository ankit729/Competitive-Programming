// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

// Example 1:

// Input: n = 12
// Output: 3 
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.

int numSquares_perfectsquare(int a){
    int rt=sqrt(a);
    return (rt*rt==a);
}
int numSquares(int n){
    if(numSquares_perfectsquare(n))
        return 1;
    while(n%4==0)
        n/=4;
    if(n%8==7)
        return 4;
    for(int i=1;i*i<n;i++)
        if(numSquares_perfectsquare(n-i*i))
            return 2;
    return 3;
}
