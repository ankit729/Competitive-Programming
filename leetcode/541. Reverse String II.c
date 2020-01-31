// Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
// Example:
// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"
// Restrictions:
// The string consists of lower English letters only.
// Length of the given string and k will in the range [1, 10000]

void swap(char* a,char* b){
    char c=*a;
    *a=*b;
    *b=c;
}
int min(int a,int b){
    return (a<b)?a:b;
}
char * reverseStr(char * s, int k){
    int i=0;
    int n=strlen(s);
    while(i<n){
        int l=i;
        int h=min(n-1,i+k-1);
        while(l<h)
            swap(&s[l++],&s[h--]);
        i+=2*k;
    }
    return s;
}
