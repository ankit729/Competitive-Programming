// Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.

// Return the maximum possible length of s.

 

// Example 1:

// Input: arr = ["un","iq","ue"]
// Output: 4
// Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
// Maximum length is 4.
// Example 2:

// Input: arr = ["cha","r","act","ers"]
// Output: 6
// Explanation: Possible solutions are "chaers" and "acters".
// Example 3:

// Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
// Output: 26
 

// Constraints:

// 1 <= arr.length <= 16
// 1 <= arr[i].length <= 26
// arr[i] contains only lower case English letters.

int max(int a,int b){
    return (a>b)?a:b;
}
int setbits(int a){
    int ans=0;
    while(a>0){
        ans+=(a&1);
        a>>=1;
    }
    return ans;
}
int maxLength_solve(int alpha[],bool is[],int r,int index,int a){
    if(index>=r)
        return a;
    int ans=maxLength_solve(alpha,is,r,index+1,a);
    if(is[index] && (a&alpha[index])==0)
        ans=max(ans,maxLength_solve(alpha,is,r,index+1,a|alpha[index]));
    return ans;
}
int maxLength(char** arr,int r){
    int alpha[r];
    bool is[r];
    memset(alpha,0,sizeof(alpha));
    memset(is,true,sizeof(is));
    for(int i=0;i<r;i++){
        for(int j=strlen(arr[i])-1;j>=0;j--){
            if((alpha[i]&(1<<(arr[i][j]-'a')))==0)
                alpha[i]|=1<<(arr[i][j]-'a');
            else{
                is[i]=false;
                break;
            }
        }
    }
    return setbits(maxLength_solve(alpha,is,r,0,0));
}
