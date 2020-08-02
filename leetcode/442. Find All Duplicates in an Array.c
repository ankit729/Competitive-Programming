// Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

// Find all the elements that appear twice in this array.

// Could you do it without extra space and in O(n) runtime?

// Example:
// Input:
// [4,3,2,7,8,2,3,1]

// Output:
// [2,3]

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums,int nr,int* rr){
    *rr=0;
    int* ra=malloc(nr*sizeof(int));
    for(int i=0;i<nr;i++){
        int j=abs(nums[i])-1;
        if(nums[j]<0)
            ra[(*rr)++]=j+1;
        nums[j]=-abs(nums[j]);
    }
    return realloc(ra,*rr*sizeof(int));
}
