int bsge(int a[],int l,int r,int x){
    int ans=-1;
    while(l<=r){
        int mid=((l+r)>>1);
        if(a[mid]<x)
            l=mid+1;
        else{
            ans=mid;
            r=mid-1;
        }
    }
    return ans;
}
