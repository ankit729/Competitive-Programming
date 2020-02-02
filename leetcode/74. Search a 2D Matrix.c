// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// Example 1:

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
// Example 2:

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false

bool searchMatrix(int** m,int r,int* c,int x){
    if(r==0 || c[0]==0)
        return false;
    int l=0,h=r*c[0]-1,mid,R,C;
    while(l<=h){
        mid=(l+h)>>1;
        R=mid/c[0];
        C=mid%c[0];
        if(m[R][C]==x)
            return true;
        if(m[R][C]>x)
            h=mid-1;
        else
            l=mid+1;
    }
    return false;
}
