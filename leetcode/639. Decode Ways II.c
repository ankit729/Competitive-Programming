// A message containing letters from A-Z is being encoded to numbers using the following mapping way:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

// Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

// Also, since the answer may be very large, you should return the output mod 109 + 7.

// Example 1:
// Input: "*"
// Output: 9
// Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
// Example 2:
// Input: "1*"
// Output: 9 + 9 = 18
// Note:
// The length of the input string will fit in range [1, 105].
// The input string will only contain the character '*' and digits '0' - '9'.

int numDecodings(char* s){
    int n=strlen(s);
    if(n==0)
        return 0;
    int MOD=1000000007;
    long int dp[n+1];
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=0;
        int temp=s[i-1]-'0';
        if(1<=temp && temp<=9)
            dp[i]=dp[i-1];
        else if(s[i-1]=='*')
            dp[i]=(dp[i-1]*9)%MOD;
        if(i>=2){
            if(s[i-2]=='*'){
                if(s[i-1]=='*')
                    dp[i]=(dp[i]+dp[i-2]*15)%MOD;
                else{
                    if(s[i-1]<='6')
                        dp[i]=(dp[i]+dp[i-2]*2)%MOD;
                    else
                        dp[i]=(dp[i]+dp[i-2])%MOD;
                }
            }
            else{
                if(s[i-1]=='*'){
                    if(s[i-2]=='1')
                        dp[i]=(dp[i]+dp[i-2]*9)%MOD;
                    else if(s[i-2]=='2')
                        dp[i]=(dp[i]+dp[i-2]*6)%MOD;
                }
                else{
                    temp=(s[i-2]-'0')*10+s[i-1]-'0';
                    if(10<=temp && temp<=26)
                        dp[i]=(dp[i]+dp[i-2])%MOD;
                }
            }
        }
    }
    return dp[n];
}
