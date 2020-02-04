// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

// Example 1:

// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:

// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int max(int a,int b){
    return (a>b)?a:b;
}
int* spiralOrder(int** m,int r,int* c,int* rr){
    if(r==0){
        *rr=0;
        return NULL;
    }
    *rr=r*c[0];
    int* a=malloc(*rr*sizeof(int));
    int lr=0,hr=r-1,lc=0,hc=c[0]-1;
    int pushcount=0;
    while(lr<=hr && lc<=hc){
        for(int i=lc;i<=hc;i++)
            a[pushcount++]=m[lr][i];
        if(pushcount==*rr)
            return a;
        lr++;
        for(int i=lr;i<=hr;i++)
            a[pushcount++]=m[i][hc];
        if(pushcount==*rr)
            return a;
        hc--;
        for(int i=hc;i>=lc;i--)
            a[pushcount++]=m[hr][i];
        if(pushcount==*rr)
            return a;
        hr--;
        for(int i=hr;i>=lr;i--)
            a[pushcount++]=m[i][lc];
        if(pushcount==*rr)
            return a;
        lc++;
    }
    return a;
}
