#include <bits/stdc++.h>
using namespace std;
#define gc getchar
#define gcu getchar_unlocked
#define ll long long int
#define pb push_back
#define pc putchar
#define pcu putchar_unlocked
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
template<typename T> void scan(T &input) {
    input=0;
    bool negative=false;
    register T c=gcu();
    if(c=='-')
        negative=true,c=gcu();
    for(;c<48 || c>57;c=gcu());
    for(;(c>47 && c<58);c=gcu())
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
		pcu('-');
	while(i>=0)
		pcu(snum[i--]);
	putchar('\n');
}
auto fastIO=[](){std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
int main() {
	
	return 0;
}
