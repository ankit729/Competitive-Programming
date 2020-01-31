// Given a positive integer, return its corresponding column title as appear in an Excel sheet.

// For example:

//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB 
//     ...
// Example 1:

// Input: 1
// Output: "A"
// Example 2:

// Input: 28
// Output: "AB"
// Example 3:

// Input: 701
// Output: "ZY"

char * convertToTitle(int N){
    int n=N,b=1;
    long long int a=26;
    while(n>a){
        n-=a;
        a*=26;
        b++;
    }
    char *ans=malloc(b+1);
    ans[b--]='\0';
    while(N>0){
        N--;
        ans[b--]='A'+(N%26);
        N/=26;
    }
    
    return ans;
}
