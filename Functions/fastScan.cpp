template<typename T> void scan(T &input) {
    input=0;
    bool negative=false;
    register T c=getchar_unlocked();
    if(c=='-')
        negative=true,c=getchar_unlocked();
    for(;c<48 || c>57;c=getchar_unlocked());
    for(;(c>47 && c<58);c=getchar_unlocked())
        input=(input<<3)+(input<<1)+(c&15);
    if(negative)
        input=-input;
}
template<typename T> void print(T output) {
	bool negative=false;
	if(output<0)
		output=-output,negative=true;
	char snum[65];
	int i=0;
	do{
		snum[i++]=output%10+'0';
		output/=10;
	}while(output);
	i--;
	if(negative)
		putchar_unlocked('-');
	while(i>=0)
		putchar_unlocked(snum[i--]);
	//putchar('\n');
}
ios_base::sync_with_stdio(false);cin.tie(NULL);
