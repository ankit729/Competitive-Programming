#include<bits/stdc++.h>
using namespace std;

vector<int> getZArr(string& s) {
    int n = s.length();
    vector<int> Z(n);
    Z[0] = 0;
    
    for(int i=1, L=0, R=0; i<n; ++i) {
        if(i > R) {
            L = R = i;
            while(R < n && s[R-L] == s[R])
                R++;
            
            Z[i] = R - L;
            R--;
        }
        else{
            int k = i - L;
            if(Z[k] < R - i + 1)
                Z[i] = Z[k];
            else{
                L = i;
                while(R < n && s[R - L] == s[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
    
    return Z;
}

void Z_algorithm(string& s, string& pattern){
	int l = pattern.length() + 1 + s.length();
	string temp = pattern + "$" + s;
	vector<int> Z = getZArr(temp);
	for(int i=0; i<l; ++i){
		if(Z[i] == pattern.length()) 
			printf("Pattern found at index %d\n", i - pattern.length() - 1);
	}
}
int main(void){
	string s = "GEEKS FOR GEEKS";
	string pattern = "GEEK";
	Z_algorithm(s, pattern);
	return 0;
}
