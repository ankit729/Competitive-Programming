#include<stdio.h>
#include<stdbool.h>
int make_super_strings(int C,int c,bool arr[C],int index,int n){
    while(index<C && (index&n)>0)
        index<<=1;
    if(index==C)
        return 0;
    int x=n|index;
    arr[x]=true;
    make_super_strings(C,c,arr,index<<1,x);
    make_super_strings(C,c,arr,index<<1,n);
    return 0;
}
int main(void){
	int c,n;
	scanf("%d %d",&c,&n);
	int C=1<<c;
	bool arr[C];
	for(int i=0;i<C;i++)
	    arr[i]=false;
	int a[n];
	for(int i=0;i<n;i++){
	    scanf("%d",&a[i]);
	    arr[a[i]]=true;
	    make_super_strings(C,c,arr,1,a[i]);
	}
	int ans=0;
	for(int i=0;i<C;i++)
	    if(arr[i])
	        ans++;
    printf("%d",ans);
	return 0;
}
