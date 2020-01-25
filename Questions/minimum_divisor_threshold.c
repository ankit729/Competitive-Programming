#include<stdio.h>
#include<math.h>
int max(int a,int b){
    if(a>b)
        return a;
    return b;
}
int minimum_divisor_threshold(int threshold,int n,int a[n],int low,int high){
    if(low==high)
        return low;
    int mid=(low+high)>>1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=ceil((float) a[i]/mid);
        if(sum>threshold)
            break;
    }
    if(sum<=threshold)
        return minimum_divisor_threshold(threshold,n,a,low,mid);
    return minimum_divisor_threshold(threshold,n,a,mid+1,high);
}
int main(void){
	int threshold,n;
	scanf("%d %d",&threshold,&n);
	int low=1,high=0;
	int a[n];
	for(int i=0;i<n;i++){
	    scanf("%d",&a[i]);
	    high=max(high,a[i]);
	}
	printf("%d\n",minimum_divisor_threshold(threshold,n,a,low,high));
	return 0;
}
