// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


// In Pascal's triangle, each number is the sum of the two numbers directly above it.

// Example:

// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int n, int* rr, int** rc){
    *rr=n;
    *rc=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        (*rc)[i]=i+1;
    int** ra=malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        ra[i]=(int*)malloc((i+1)*sizeof(int));
        ra[i][0]=ra[i][i]=1;
    }
    for(int i=2;i<n;i++)
        for(int j=1;j<i;j++)
            ra[i][j]=ra[i-1][j-1]+ra[i-1][j];
    return ra;
}
