// Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

 

// Example 1:

// Input:
// [[0,0,0],
//  [0,1,0],
//  [0,0,0]]

// Output:
// [[0,0,0],
//  [0,1,0],
//  [0,0,0]]
// Example 2:

// Input:
// [[0,0,0],
//  [0,1,0],
//  [1,1,1]]

// Output:
// [[0,0,0],
//  [0,1,0],
//  [1,2,1]]
 

// Note:

// The number of elements of the given matrix will not exceed 10,000.
// There are at least one 0 in the given matrix.
// The cells are adjacent in only four directions: up, down, left and right.

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int min(int a,int b){
    return (a<b)?a:b;
}
int** updateMatrix(int** a, int r, int* c, int* rr, int** rc){
    *rr=r;
    rc[0]=c;
    int MAX=r*c[0];
    for(int i=0;i<r;i++)
        for(int j=0;j<c[i];j++)
            if(a[i][j]>0)
                a[i][j]=MAX;
    for(int i=0;i<r;i++)
        for(int j=0;j<c[i];j++){
            if(i>0)
                a[i][j]=min(a[i][j],a[i-1][j]+1);
            if(j>0)
                a[i][j]=min(a[i][j],a[i][j-1]+1);
        }
    for(int i=r-1;i>=0;i--)
        for(int j=c[i]-1;j>=0;j--){
            if(i<r-1)
                a[i][j]=min(a[i][j],a[i+1][j]+1);
            if(j<c[i]-1)
                a[i][j]=min(a[i][j],a[i][j+1]+1);
        }
    return a;
}
