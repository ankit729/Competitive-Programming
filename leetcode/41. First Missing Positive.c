// Given an unsorted integer array, find the smallest missing positive integer.

// Example 1:

// Input: [1,2,0]
// Output: 3
// Example 2:

// Input: [3,4,-1,1]
// Output: 2
// Example 3:

// Input: [7,8,9,11,12]
// Output: 1

void swap(int* nums,int i,int j){
    int t=nums[i];
    nums[i]=nums[j];
    nums[j]=t;
}
int firstMissingPositive(int* nums,int nr){
    for(int i=0;i<nr;i++)
        while(!(nums[i]==i+1 || nums[i]<=0 || nums[i]>nr)){
            if(nums[i]==nums[nums[i]-1])
                break;
            swap(nums,i,nums[i]-1);
        }
    int i=0;
    while(i<nr && nums[i]==i+1)
        i++;
    return i+1;
}
