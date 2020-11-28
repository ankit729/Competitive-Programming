#include <bits/stdc++.h>
using namespace std;
#define GC getchar
#define GCU getchar_unlocked
#define PC putchar
#define PCU putchar_unlocked
template<typename T> void scan(T &input) {
    input=0;
    bool negative=false;
    register T c=GCU();
    if(c=='-')
        negative=true,c=GCU();
    for(;c<48 || c>57;c=GCU());
    for(;(c>47 && c<58);c=GCU())
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
		PCU('-');
	while(i>=0)
		PCU(snum[i--]);
	putchar('\n');
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	return 0;
}
