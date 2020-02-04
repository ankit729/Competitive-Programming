// On a 2 dimensional grid with R rows and C columns, we start at (r0, c0) facing east.

// Here, the north-west corner of the grid is at the first row and column, and the south-east corner of the grid is at the last row and column.

// Now, we walk in a clockwise spiral shape to visit every position in this grid. 

// Whenever we would move outside the boundary of the grid, we continue our walk outside the grid (but may return to the grid boundary later.) 

// Eventually, we reach all R * C spaces of the grid.

// Return a list of coordinates representing the positions of the grid in the order they were visited.

 

// Example 1:

// Input: R = 1, C = 4, r0 = 0, c0 = 0
// Output: [[0,0],[0,1],[0,2],[0,3]]


 

// Example 2:

// Input: R = 5, C = 6, r0 = 1, c0 = 4
// Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]


 

// Note:

// 1 <= R <= 100
// 1 <= C <= 100
// 0 <= r0 < R
// 0 <= c0 < C

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrixIII(int R,int C,int r0,int c0,int* rr,int** rc){
    int count=R*C,pushcount=0;
    *rr=count;
    *rc=malloc(count*sizeof(int));
    int** a=malloc(count*sizeof(int*));
    for(int i=count-1;i>=0;i--){
        a[i]=(int*)malloc(2*sizeof(int));
        rc[0][i]=2;
    }
    int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    a[pushcount][0]=r0;
    a[pushcount][1]=c0;
    pushcount++;
    int n=1,d=0;
    while(pushcount<count){
        int i=0;
        if(r0<0 || r0>=R || c0<0 || c0>=C){
            int x;
            if(d==0){
                x=-1-c0;
                c0+=(x<0)?n:x;
                i=(x<0)?n:x;
            }
            else if(d==1){
                x=-1-r0;
                r0+=(x<0)?n:x;
                i=(x<0)?n:x;
            }
            else if(d==2){
                x=c0-C;
                c0-=(x<0)?n:x;
                i=(x<0)?n:x;
            }
            else{
                x=r0-R;
                r0-=(x<0)?n:x;
                i=(x<0)?n:x;
            }
        }
        for(;i<n;i++){
            r0+=dir[d][0];
            c0+=dir[d][1];
            if(r0>=0 && r0<R && c0>=0 && c0<C){
                a[pushcount][0]=r0;
                a[pushcount][1]=c0;
                pushcount++;
            }
            else{
                r0+=(n-i-1)*dir[d][0];
                c0+=(n-i-1)*dir[d][1];
                break;
            }
        }
        d++;
        if(d==4)
            d=0;
        if(!(d&1))
            n++;
    }
    return a;
}
