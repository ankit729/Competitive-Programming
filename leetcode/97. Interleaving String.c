// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

// Example 1:

// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
// Example 2:

// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false

bool isInterleave_Util(char* s1,int i,char* s2,int j,char* s3,int r1,int r2,int memo[r1][r2]){
    if(i==r1)
        return strcmp(s2+j,s3+i+j)==0;
    if(j==r2)
        return strcmp(s1+i,s3+i+j)==0;
    if(memo[i][j]!=-1)
        return memo[i][j]==1;
    bool ans=false;
    if(s1[i]==s3[i+j])
        ans=isInterleave_Util(s1,i+1,s2,j,s3,r1,r2,memo);
    if(s2[j]==s3[i+j])
        ans|=isInterleave_Util(s1,i,s2,j+1,s3,r1,r2,memo);
    memo[i][j]=ans;
    return ans;
}
bool isInterleave(char* s1,char* s2,char* s3){
    int r1=strlen(s1);
    int r2=strlen(s2);
    int r3=strlen(s3);
    if(r1+r2!=r3)
        return false;
    if(r1==0 && r2==0)
        return true;
    if(r1==0)
        return strcmp(s2,s3)==0;
    if(r2==0)
        return strcmp(s1,s3)==0;
    int memo[r1][r2];
    memset(memo,-1,sizeof(memo));
    return isInterleave_Util(s1,0,s2,0,s3,r1,r2,memo);
}
