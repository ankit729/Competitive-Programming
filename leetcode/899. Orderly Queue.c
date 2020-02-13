// A string S of lowercase letters is given.  Then, we may make any number of moves.

// In each move, we choose one of the first K letters (starting from the left), remove it, and place it at the end of the string.

// Return the lexicographically smallest string we could have after any number of moves.

 

// Example 1:

// Input: S = "cba", K = 1
// Output: "acb"
// Explanation: 
// In the first move, we move the 1st character ("c") to the end, obtaining the string "bac".
// In the second move, we move the 1st character ("b") to the end, obtaining the final result "acb".
// Example 2:

// Input: S = "baaca", K = 3
// Output: "aaabc"
// Explanation: 
// In the first move, we move the 1st character ("b") to the end, obtaining the string "aacab".
// In the second move, we move the 3rd character ("c") to the end, obtaining the final result "aaabc".
 

// Note:

// 1 <= K <= S.length <= 1000
// S consists of lowercase letters only.

int compare(const void* a,const void* b){
    return (*(char*)a-*(char*)b);
}
bool orderlyQueue_comparestrings(char* S,int x,int y){
    int n=strlen(S);
    for(int i=0;i<n;i++){
        if(S[x]<S[y])
            return false;
        if(S[y]<S[x])
            return true;
        x++;y++;
        if(x==n)
            x=0;
        if(y==n)
            y=0;
    }
    return false;
}
char* orderlyQueue(char* S,int K){
    int n=strlen(S);
    if(K==1){
        int index=0;
        for(int i=1;i<n;i++)
            if(orderlyQueue_comparestrings(S,index,i))
                index=i;
        char* s=malloc((n+1)*sizeof(char));
        for(int i=0;i<n;i++)
            s[i]=S[(index+i)%n];
        s[n]=NULL;
        return s;
    }
    qsort(S,n,sizeof(char),compare);
    return S;
}
