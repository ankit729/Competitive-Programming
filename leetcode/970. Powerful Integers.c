// Given two positive integers x and y, an integer is powerful if it is equal to x^i + y^j for some integers i >= 0 and j >= 0.

// Return a list of all powerful integers that have value less than or equal to bound.

// You may return the answer in any order.  In your answer, each value should occur at most once.

 

// Example 1:

// Input: x = 2, y = 3, bound = 10
// Output: [2,3,4,5,7,9,10]
// Explanation: 
// 2 = 2^0 + 3^0
// 3 = 2^1 + 3^0
// 4 = 2^0 + 3^1
// 5 = 2^1 + 3^1
// 7 = 2^2 + 3^1
// 9 = 2^3 + 3^0
// 10 = 2^0 + 3^2
// Example 2:

// Input: x = 3, y = 5, bound = 15
// Output: [2,4,6,8,10,14]
 

// Note:

// 1 <= x <= 100
// 1 <= y <= 100
// 0 <= bound <= 10^6

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* powerfulIntegers(int x,int y,int bound,int* rr){
    if(bound<=1){
        *rr=0;
        return NULL;
    }
    int xr=(x>1)?1+log(bound)/log(x):1;
    int yr=(y>1)?1+log(bound)/log(y):1;
    int X[xr],Y[yr];
    X[0]=Y[0]=1;
    for(int i=1;i<xr;i++)
        X[i]=X[i-1]*x;
    for(int i=1;i<yr;i++)
        Y[i]=Y[i-1]*y;
    bool a[bound];
    memset(a,false,sizeof(a));
    for(int i=0;i<xr;i++){
        for(int j=0;j<yr;j++){
            int sum=X[i]+Y[j];
            if(sum>bound)
                break;
            a[sum-1]=true;
        }
    }
    int* ra=malloc(bound*sizeof(int));
    *rr=0;
    for(int i=0;i<bound;i++)
        if(a[i]==true)
            ra[(*rr)++]=i+1;
    printf("%d",*rr);
    return ((*rr>0)?(int*)realloc(ra,(*rr)*sizeof(int)):NULL);
}
