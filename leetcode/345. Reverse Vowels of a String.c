// Write a function that takes a string as input and reverse only the vowels of a string.

// Example 1:

// Input: "hello"
// Output: "holle"
// Example 2:

// Input: "leetcode"
// Output: "leotcede"

void swap(char* a,char* b){
    char c=*a;
    *a=*b;
    *b=c;
}
char * reverseVowels(char * s){
    int n=strlen(s);
    int l=0,h=n-1;
    while(l<h){
        while(l<h && s[l]!='a' && s[l]!='e' && s[l]!='i' && s[l]!='o' && s[l]!='u' && s[l]!='A' && s[l]!='E' && s[l]!='I' && s[l]!='O' && s[l]!='U')
            l++;
        while(h>l && s[h]!='a' && s[h]!='e' && s[h]!='i' && s[h]!='o' && s[h]!='u' && s[h]!='A' && s[h]!='E' && s[h]!='I' && s[h]!='O' && s[h]!='U')
            h--;
        swap(&s[l],&s[h]);
        l++;
        h--;
    }
    return s;
}
