// A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

// Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.

 

// Example 1:


// Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
// Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 100
// 1 <= mat[i][j] <= 100

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> mat) {
        int R=mat.size(),C=mat[0].size();
        int a[min(R,C)];
        for(int c=0;c<C;++c)
            helper(mat,R,C,0,c);
        for(int r=1;r<R;++r)
            helper(mat,R,C,r,0);
        return mat;
    }
private:
    void helper(vector<vector<int>>& mat, int R, int C, int r, int c) {
        int a[min(R,C)],i=0;
        for(;r<R && c<C;++r,++c)
            a[i++]=mat[r][c];
        sort(a,a+i);
        for(--r,--c;r>=0 && c>=0;--r,--c)
            mat[r][c]=a[--i];
    }
};
