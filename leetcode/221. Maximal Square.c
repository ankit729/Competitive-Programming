// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// Example:

// Input: 

// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0

// Output: 4

int max(int a,int b){
    return (a>b)?a:b;
}
int min(int a,int b){
    return (a<b)?a:b;
}
int maximalSquare(char** M, int r, int* c){
    if(r==0 || c[0]==0)
        return 0;
    int a=0;
    int m[r][c[0]];
    for(int i=0;i<r;i++)
        for(int j=0;j<c[i];j++)
            m[i][j]=M[i][j]-'0';
    for(int i=1;i<r;i++)
        for(int j=1;j<c[i];j++)
            if(m[i][j])
                m[i][j]=1+min(m[i-1][j],min(m[i-1][j-1],m[i][j-1]));
    for(int i=0;i<r;i++)
        for(int j=0;j<c[i];j++)
            a=max(a,m[i][j]);
    return a*a;
}
