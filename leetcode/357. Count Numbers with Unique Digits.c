// Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

// Example:

// Input: 2
// Output: 91 
// Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, 
//              excluding 11,22,33,44,55,66,77,88,99

int countNumbersWithUniqueDigits(int n){
    if(n>10)
        n=10;
    int ans=1;
    for(int i=1;i<=n;i++){
        int p=9;
        for(int j=1;j<i;j++)
            p*=9-j+1;
        ans+=p;
    }
    return ans;
}
