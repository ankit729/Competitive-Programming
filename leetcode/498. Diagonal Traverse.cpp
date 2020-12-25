// Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

 

// Example:

// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]

// Output:  [1,2,4,7,5,3,6,8,9]

// Explanation:

 

// Note:

// The total number of elements of the given matrix will not exceed 10,000.

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int R=matrix.size(),C=(R>0)?matrix[0].size():0;
        vector<int> ans;
        ans.reserve(R*C);
        int r=0,c=0,d=1;
        bool flag=true;
        while(r<R && c<C){
            while(r>=0 && r<R && c>=0 && c<C){
                ans.push_back(matrix[r][c]);
                r-=d,c+=d;
            }
            r+=d,c-=d;
            if(flag){
                if(c+1<C)
                    c++;
                else
                    r++;
            }
            else{
                if(r+1<R)
                    r++;
                else
                    c++;
            }
            d=-d;
            flag=!flag;
        }
        return ans;
    }
};
