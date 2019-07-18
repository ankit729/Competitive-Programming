void swap(ll* a,ll* b){
	ll t=*a;
	*a=*b;
	*b=t;
}
int partition(ll arr[],ll low,ll high){
	ll pivot=arr[high];
	ll i=low-1;
	for(ll j=low;j<=high-1;j++){
		if(arr[j]<=pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}
void quickSort(ll arr[],ll low,ll high){
	if(low<high){
		ll pi=partition(arr,low,high);
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);
	}
}