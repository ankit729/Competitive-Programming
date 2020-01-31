// Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

// Example 1:
// Input: "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// Note: In the string, each word is separated by single space and there will not be any extra space in the string.

void swap(char* a,char* b){
    char c=*a;
    *a=*b;
    *b=c;
}
char * reverseWords(char * s){
    int i=0;
    int n=strlen(s);
    while(i<n){
        int l=i;
        int h=i+1;
        while(s[h]!=' ' && h<n)
            h++;
        i=h+1;
        h--;
        while(l<h)
            swap(&s[l++],&s[h--]);
    }
    return s;
}
