// We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.

// The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].

// The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].

// Return true if and only if the number of global inversions is equal to the number of local inversions.

// Example 1:

// Input: A = [1,0,2]
// Output: true
// Explanation: There is 1 global inversion, and 1 local inversion.
// Example 2:

// Input: A = [1,2,0]
// Output: false
// Explanation: There are 2 global inversions, and 1 local inversion.
// Note:

// A will be a permutation of [0, 1, ..., A.length - 1].
// A will have length in range [1, 5000].
// The time limit for this problem has been reduced.

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n=A.size();
        if(n<=2)
            return true;
        int M1=0,M2=1;
        if(A[M1]<A[M2])
            swap(M1,M2);
        for(int i=2;i<n;++i){
            if((M1+1<i && A[M1]>A[i]) || (M2+1<i && A[M2]>A[i]))
                return false;
            if(A[i]>A[M1]){
                M2=M1;
                M1=i;
            }
            else if(A[i]>A[M2])
                M2=i;
        }
        return true;
    }
};
