// We have a sorted set of digits D, a non-empty subset of {'1','2','3','4','5','6','7','8','9'}.  (Note that '0' is not included.)

// Now, we write numbers using these digits, using each digit as many times as we want.  For example, if D = {'1','3','5'}, we may write numbers such as '13', '551', '1351315'.

// Return the number of positive integers that can be written (using the digits of D) that are less than or equal to N.

 

// Example 1:

// Input: D = ["1","3","5","7"], N = 100
// Output: 20
// Explanation: 
// The 20 numbers that can be written are:
// 1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
// Example 2:

// Input: D = ["1","4","9"], N = 1000000000
// Output: 29523
// Explanation: 
// We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
// 81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
// 2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
// In total, this is 29523 integers that can be written using the digits of D.
 

// Note:

// D is a subset of digits '1'-'9' in sorted order.
// 1 <= N <= 10^9

int atMostNGivenDigitSet(char** D,int DSize,int N){
    int n=1+log10(N);
    int count[10];
    memset(count,0,sizeof(count));
    for(int i=0;i<DSize;i++)
        count[atoi(D[i])]++;
    for(int i=1;i<10;i++)
        count[i]+=count[i-1];
    int dp[n];
    memset(dp,0,sizeof(dp));
    int p10=pow(10,n-1);
    int numdigits=n-1;
    while(N>0){
        int digit=N/p10;
        if(count[digit]>0){
            if(count[digit]-count[digit-1]){
                dp[numdigits]+=count[digit]-1;
                if(N<10)
                    dp[0]++;
            }
            else{
                dp[numdigits]+=count[digit];
                break;
            }
        }
        else
            break;
        numdigits--;
        N%=p10;
        p10/=10;
    }
    int p=1;
    for(int i=1;i<n;i++)
        dp[0]+=(dp[i]+1)*(p*=DSize);
    return dp[0];
}
