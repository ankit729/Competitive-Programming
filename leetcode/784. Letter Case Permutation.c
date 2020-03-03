// Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

// Examples:
// Input: S = "a1b2"
// Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

// Input: S = "3z4"
// Output: ["3z4", "3Z4"]

// Input: S = "12345"
// Output: ["12345"]
// Note:

// S will be a string with length between 1 and 12.
// S will consist only of letters or digits.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCasePermutation(char* S,int* rr){
    int size=0;
    int i=0;
    while(S[i]!=NULL)
        if(isalpha(S[i++]))
            size++;
    *rr=(1<<size);
    int n=strlen(S);
    char **ra=malloc(*rr*sizeof(char*));
    for(i=0;i<*rr;i++){
        ra[i]=(char*)malloc((n+1)*sizeof(char));
        ra[i][n]=NULL;
    }
    size=(*rr>>1);
    for(i=0;i<n;i++){
        if(isalpha(S[i])==0){
            for(int j=0;j<*rr;j++)
                ra[j][i]=S[i];
            continue;
        }
        bool flag=false;
        int a=0;
        char l=tolower(S[i]),u=toupper(S[i]);
        for(int j=0;j<*rr;j++){
            if(!flag)
                ra[j][i]=l;
            else
                ra[j][i]=u;
            a++;
            if(a==size){
                a=0;
                flag=!flag;
            }
        }
        size>>=1;
    }
    return ra;
}
