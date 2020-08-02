// Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

// Find all the elements of [1, n] inclusive that do not appear in this array.

// Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

// Example:

// Input:
// [4,3,2,7,8,2,3,1]

// Output:
// [5,6]

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findDisappearedNumbers(int* nums,int nr,int* rr){
    *rr=0;
    for(int i=0;i<nr;i++){
        int j=abs(nums[i])-1;
        nums[j]=-abs(nums[j]);
    }
    *rr=0;
    for(int i=0;i<nr;i++)
        if(nums[i]>0)
            (*rr)++;
    int* ra=malloc(*rr*sizeof(int));
    int j=0;
    for(int i=0;i<nr;i++)
        if(nums[i]>0)
            ra[j++]=i+1;
    return ra;
}
