// An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

// Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

// To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

// At the end, return the modified image.

// Example 1:
// Input: 
// image = [[1,1,1],[1,1,0],[1,0,1]]
// sr = 1, sc = 1, newColor = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]
// Explanation: 
// From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
// by a path of the same color as the starting pixel are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally connected
// to the starting pixel.
// Note:

// The length of image and image[0] will be in the range [1, 50].
// The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
// The value of each color in image[i][j] and newColor will be an integer in [0, 65535].

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int change(int** a,int r,int* c,int t,int nc,int i,int j){
    if(i<0 || i>=r || j<0 || j>=*c)
        return;
    if(a[i][j]==t){
        a[i][j]=nc;
        change(a,r,c,t,nc,i-1,j);
        change(a,r,c,t,nc,i,j+1);
        change(a,r,c,t,nc,i+1,j);
        change(a,r,c,t,nc,i,j-1);
    }
    return;
}
int** floodFill(int** image,int r,int* c,int sr,int sc,int nc,int* rr,int** rc){
    int **a=malloc(r*sizeof(int *));
    for(int i=0;i<r;i++)
        a[i]=(int *)malloc((*c)*sizeof(int));
    for(int i=0;i<r;i++)
        for(int j=0;j<*c;j++)
            a[i][j]=image[i][j];
    *rr=r;
    rc[0]=c;
    int t=a[sr][sc];
    if(t==nc)
        return a;
    change(a,r,c,t,nc,sr,sc);
    return a;
}
