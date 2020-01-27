#include<stdio.h>
int max(int a,int b){
    if(a>b)
        return a;
    return b;
}
int min(int a,int b){
    if(a<b)
        return a;
    return b;
}
int jump_game_2(int n,int a[n]){
    int maxReach=a[0];
    int step=a[0];
    int jump=1;
    for(int i=1;i<n;i++){
        if(i==n-1)
            return jump;
        maxReach=max(maxReach,i+a[i]);
        step--;
        if(step==0){
            jump++;
            if(i>=maxReach)
                return -1;
            step=maxReach-i;
        }
    }
    return -1;
}
int activate_fountain(){
    int n,i;
	scanf("%d",&n);
	int a[n+1];
	for(i=0;i<=n;i++)
	    a[i]=0;
	for(i=0;i<n;i++){
	    int x;
	    scanf("%d",&x);
	    int y=max(i-x,0);
	    int z=min(i+x,n-1);
	    a[y]=max(a[y],z-y);
	}
	for(i=0;i<n;i++)
	    a[i]++;
    return jump_game_2(n+1,a);
}
int main(void){
	printf("%d",activate_fountain());
	return 0;
}
