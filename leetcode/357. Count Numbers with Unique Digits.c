// Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

// Example:

// Input: 2
// Output: 91 
// Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, 
//              excluding 11,22,33,44,55,66,77,88,99

int countNumbersWithUniqueDigits(int n){
    if(n==0)
        return 1;
    if(n==1)
        return 10;
    if(n>10)
        n=10;
    int ans=10;
    int p=9;
    for(int i=2;i<=n;i++)
        ans+=(p*=9-i+2);
    return ans;
}
