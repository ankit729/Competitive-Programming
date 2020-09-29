int bsle(int a[],int l,int r,int x){
    int ans=-1;
    while(l<=r){
        int mid=((l+r)>>1);
        if(a[mid]<=x){
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return ans;
}
