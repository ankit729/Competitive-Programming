// We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

// You're given the startTime , endTime and profit arrays, you need to output the maximum profit you can take such that there are no 2 jobs in the subset with overlapping time range.

// If you choose a job that ends at time X you will be able to start another job that starts at time X.

 

// Example 1:



// Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
// Output: 120
// Explanation: The subset chosen is the first and fourth job. 
// Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
// Example 2:




// Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
// Output: 150
// Explanation: The subset chosen is the first, fourth and fifth job. 
// Profit obtained 150 = 20 + 70 + 60.
// Example 3:



// Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
// Output: 6
 

// Constraints:

// 1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
// 1 <= startTime[i] < endTime[i] <= 10^9
// 1 <= profit[i] <= 10^4

int compare(const void* a,const void* b){
    int* arr1=(int*)a;
    int* arr2=(int*)b;
    return (arr1[0]-arr2[0]);
}
int max(int a,int b){
    return (a>b)?a:b;
}
int jobScheduling_find_next(int n,int jobs[n][3],int cur,int l,int h){
    if(l==h)
        return (jobs[cur][1]<=jobs[l][0])?l:-1;
    if(l<h){
        int mid=(l+h)>>1;
        if(jobs[cur][1]<=jobs[mid][0])
            return jobScheduling_find_next(n,jobs,cur,l,mid);
        else
            return jobScheduling_find_next(n,jobs,cur,mid+1,h);
    }
    return -1;
}
int jobScheduling(int* startTime,int sr,int* endTime,int er,int* profit,int pr){
    int n=sr,jobs[n][3];
    for(int i=0;i<n;i++){
        jobs[i][0]=startTime[i];
        jobs[i][1]=endTime[i];
        jobs[i][2]=profit[i];
    }
    qsort(jobs,n,sizeof(jobs[0]),compare);
    int dp[n];
    dp[n-1]=jobs[n-1][2];
    for(int i=n-2;i>=0;i--){
        int next=jobScheduling_find_next(n,jobs,i,i+1,n-1);
        dp[i]=max(jobs[i][2]+((next==-1)?0:dp[next]),dp[i+1]);
    }
    return dp[0];
}
